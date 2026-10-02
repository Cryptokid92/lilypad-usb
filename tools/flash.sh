#!/usr/bin/env bash
# Flash en sketch fra ~/.local/share/lilypad-usb/sketches/<navn>/
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
NAME="${1:-}"
PORT="${PORT:-/dev/ttyACM0}"
BOARD="${BOARD:-arduino:avr:LilyPadUSB}"

if [[ -z "$NAME" ]]; then
  echo "Bruk: $0 <sketch-mappenavn>"
  echo "Tilgjengelig:"
  ls -1 "$ROOT/sketches"
  exit 1
fi

SKETCH="$ROOT/sketches/$NAME"
[[ -d "$SKETCH" ]] || { echo "Finnes ikke: $SKETCH"; exit 1; }
[[ -e "$PORT" ]] || { echo "Ingen enhet på $PORT — plugg inn LilyPad"; exit 1; }

command -v arduino-cli >/dev/null || {
  echo "arduino-cli mangler. Kjør: sudo pacman -S arduino-cli"
  exit 1
}

echo "==> compile $NAME ($BOARD)"
arduino-cli compile -b "$BOARD" "$SKETCH"
echo "==> upload → $PORT"
arduino-cli upload -b "$BOARD" -p "$PORT" "$SKETCH"
echo "OK: $NAME flashet"
