#!/usr/bin/env python3
"""Write sketches/<id>/<id>.ino from catalog.json."""

import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CATALOG_PATH = ROOT / "catalog.json"
SKETCH_ROOT = ROOT / "sketches"
HAND_SKETCHES = frozenset({"demo-hello"})
MARK = "// Generated from catalog.json"

CATEGORIES = frozenset({"demo", "egen-maskin", "lab-omarchy"})
ENTRY_FIELDS = frozenset(
    {"id", "title", "category", "vibe", "boot_delay_ms", "steps"}
)
KEY_CODES = {
    "RETURN": "KEY_RETURN",
    "TAB": "KEY_TAB",
    "ESC": "KEY_ESC",
    "BACKSPACE": "KEY_BACKSPACE",
}
MOD_CODES = {
    "GUI": "KEY_LEFT_GUI",
    "CTRL": "KEY_LEFT_CTRL",
    "ALT": "KEY_LEFT_ALT",
    "SHIFT": "KEY_LEFT_SHIFT",
}
STEP_FIELDS = {
    "delay": frozenset({"op", "ms"}),
    "print": frozenset({"op", "text"}),
    "println": frozenset({"op", "text"}),
    "key": frozenset({"op", "code"}),
    "mod": frozenset({"op", "keys"}),
    "release": frozenset({"op"}),
}


def die(message):
    print(f"generate_sketches.py: {message}", file=sys.stderr)
    raise SystemExit(1)


def printable_ascii(value, label, limit):
    if not isinstance(value, str) or not value or len(value) > limit:
        die(f"{label} must be 1 to {limit} characters")
    for char in value:
        if ord(char) < 32 or ord(char) > 126:
            die(f"{label} must be printable ASCII")


def whole_ms(value, label, low, high):
    if isinstance(value, bool) or not isinstance(value, int):
        die(f"{label} must be an integer")
    if value < low or value > high:
        die(f"{label} must be {low} to {high}")


def kebab_id(value):
    if not isinstance(value, str) or not value:
        die("id must be a kebab string")
    parts = value.split("-")
    if any(not part or not part.isalnum() or not part.islower() for part in parts):
        die(f"id {value!r} must be lowercase kebab-case")
    if value in HAND_SKETCHES:
        die(f"{value} is a hand sketch and cannot come from the catalog")


def c_string(text):
    return '"' + text.replace("\\", "\\\\").replace('"', '\\"') + '"'


def validate_step(step, entry_id, index):
    where = f"{entry_id} step {index}"
    if not isinstance(step, dict) or "op" not in step:
        die(f"{where} needs an op")
    op = step["op"]
    if op not in STEP_FIELDS:
        die(f"{where} has unknown op {op!r}")
    if set(step) != STEP_FIELDS[op]:
        die(f"{where} has the wrong fields for {op}")
    if op == "delay":
        whole_ms(step["ms"], f"{where} ms", 0, 60000)
    elif op in {"print", "println"}:
        printable_ascii(step["text"], f"{where} text", 180)
    elif op == "key":
        if step["code"] not in KEY_CODES:
            die(f"{where} has unknown key {step['code']!r}")
    elif op == "mod":
        keys = step["keys"]
        if not isinstance(keys, list) or not keys or len(keys) > 4:
            die(f"{where} needs 1 to 4 keys")
        for key in keys:
            if key in MOD_CODES:
                continue
            if isinstance(key, str) and len(key) == 1 and key.isalnum():
                continue
            die(f"{where} has bad key {key!r}")
        if not any(key in MOD_CODES for key in keys):
            die(f"{where} needs a modifier")


def require_gui_wait(steps, entry_id):
    for index, step in enumerate(steps):
        if step["op"] != "mod" or "GUI" not in step["keys"]:
            continue
        ready = False
        for later in steps[index + 1 :]:
            if later["op"] == "delay" and 800 <= later["ms"] <= 1200:
                ready = True
                break
            if later["op"] in {"print", "println", "key"}:
                break
        if not ready:
            die(f"{entry_id} needs 800 to 1200 ms after GUI before typing")


def validate(entries):
    if not isinstance(entries, list) or not entries:
        die("catalog.json must be a non-empty array")
    seen = set()
    for entry in entries:
        if not isinstance(entry, dict) or set(entry) != ENTRY_FIELDS:
            die("each payload needs id, title, category, vibe, boot_delay_ms, steps")
        kebab_id(entry["id"])
        if entry["id"] in seen:
            die(f"duplicate id {entry['id']}")
        seen.add(entry["id"])
        printable_ascii(entry["title"], f"{entry['id']} title", 60)
        printable_ascii(entry["vibe"], f"{entry['id']} vibe", 80)
        if entry["category"] not in CATEGORIES:
            die(f"{entry['id']} has unknown category {entry['category']!r}")
        whole_ms(entry["boot_delay_ms"], f"{entry['id']} boot_delay_ms", 1500, 2500)
        steps = entry["steps"]
        if not isinstance(steps, list) or not steps or len(steps) > 40:
            die(f"{entry['id']} needs 1 to 40 steps")
        for index, step in enumerate(steps, start=1):
            validate_step(step, entry["id"], index)
        require_gui_wait(steps, entry["id"])
    return entries


def render_step(step):
    op = step["op"]
    if op == "delay":
        return [f"  delay({step['ms']});"]
    if op == "print":
        return [f"  Keyboard.print({c_string(step['text'])});"]
    if op == "println":
        return [f"  Keyboard.println({c_string(step['text'])});"]
    if op == "key":
        return [f"  Keyboard.write({KEY_CODES[step['code']]});"]
    if op == "release":
        return ["  Keyboard.releaseAll();"]
    lines = []
    last = len(step["keys"]) - 1
    for index, key in enumerate(step["keys"]):
        token = MOD_CODES[key] if key in MOD_CODES else f"'{key}'"
        lines.append(f"  Keyboard.press({token});")
        if index != last:
            lines.append("  delay(30);")
    return lines


def render_sketch(entry):
    body = [
        MARK,
        "#include <Keyboard.h>",
        "",
        "void setup() {",
        f"  delay({entry['boot_delay_ms']});",
        "  Keyboard.begin();",
        "  delay(200);",
    ]
    for step in entry["steps"]:
        body.extend(render_step(step))
    body.extend(
        [
            "  delay(100);",
            "  Keyboard.end();",
            "}",
            "",
            "void loop() {}",
            "",
        ]
    )
    return "\n".join(body)


def write_text(path, text):
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.is_file() and path.read_text(encoding="utf-8") == text:
        return
    temporary = path.with_suffix(path.suffix + ".tmp")
    temporary.write_text(text, encoding="utf-8")
    temporary.replace(path)


def remove_stale(wanted):
    if not SKETCH_ROOT.is_dir():
        return
    for child in SKETCH_ROOT.iterdir():
        if not child.is_dir() or child.name in wanted or child.name in HAND_SKETCHES:
            continue
        sketch = child / f"{child.name}.ino"
        if not sketch.is_file():
            continue
        if MARK not in sketch.read_text(encoding="utf-8"):
            continue
        extras = [item for item in child.iterdir() if item != sketch]
        if extras:
            die(f"{child} has extra files, so stale cleanup stopped")
        sketch.unlink()
        child.rmdir()


def main():
    try:
        raw = json.loads(CATALOG_PATH.read_text(encoding="utf-8"))
    except FileNotFoundError:
        die(f"missing {CATALOG_PATH}")
    except json.JSONDecodeError as exc:
        die(f"catalog.json is not valid JSON ({exc.lineno})")
    entries = validate(raw)
    SKETCH_ROOT.mkdir(parents=True, exist_ok=True)
    for leftover in SKETCH_ROOT.glob("*/*.ino.tmp"):
        leftover.unlink()
    wanted = set()
    for entry in entries:
        wanted.add(entry["id"])
        destination = SKETCH_ROOT / entry["id"] / f"{entry['id']}.ino"
        write_text(destination, render_sketch(entry))
    remove_stale(wanted)
    print(f"ok {len(entries)} sketches")


if __name__ == "__main__":
    main()
