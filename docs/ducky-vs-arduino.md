# Duckyscript vs Arduino på LilyPad

| Hak5 Rubber Ducky | LilyPad USB |
|-------------------|-------------|
| Duckyscript → `inject.bin` | Arduino `.ino` → flash |
| Ofte USB-disk for payloads | Ingen payload-filer på disken |
| `STRING`, `DELAY`, `GUI r` | `Keyboard.print()`, `delay()`, `Keyboard.press(KEY_LEFT_GUI)` |

## Vanlige kommandoer (oversettelse)

| Duckyscript | Arduino |
|-------------|---------|
| `DELAY 500` | `delay(500);` |
| `STRING hello` | `Keyboard.print("hello");` |
| `ENTER` | `Keyboard.write(KEY_RETURN);` |
| `GUI r` | `Keyboard.press(KEY_LEFT_GUI); Keyboard.press('r'); Keyboard.releaseAll();` |
| `CTRL ALT t` | `Keyboard.press(KEY_LEFT_CTRL); Keyboard.press(KEY_LEFT_ALT); Keyboard.press('t'); Keyboard.releaseAll();` |

Konverteringsverktøy (valgfritt): søk `duck2spark` / lignende — sjekk alltid output før flash.
