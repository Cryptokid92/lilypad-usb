# lilypad-usb

Fun HID keyboard payloads for a **SparkFun LilyPad USB** (`1b4f:9208`, ATmega32U4).

Own machines and authorized labs only. No theft scripts. No “prank your coworker” payloads.

## Quick start

```bash
# regenerate sketches from the catalog
python3 tools/generate_sketches.py

# flash one (needs arduino-cli + dialout)
tools/flash.sh foot-btop
```

Board FQBN: `arduino:avr:LilyPadUSB`  
Port: usually `/dev/ttyACM0`

## Layout

| Path | Role |
|------|------|
| `catalog.json` | Source of truth for the 20 fun payloads |
| `tools/generate_sketches.py` | Writes `sketches/<id>/<id>.ino` |
| `tools/flash.sh` | Compile + upload one sketch |
| `docs/TOP20.md` | Human table of payloads |
| `docs/flash.md` | Setup on Arch/Omarchy |
| `AWESOME.md` | Awesome lists and related repos |

## Docs

- [TOP20 payloads](docs/TOP20.md)
- [Flash guide](docs/flash.md)
- [Device notes](docs/enhet.md)
- [Duckyscript ↔ Arduino](docs/ducky-vs-arduino.md)
- [Awesome lists](AWESOME.md)

## Ethics

Plug this into hardware you own or are allowed to automate.
If a payload would surprise someone else, delete it.
