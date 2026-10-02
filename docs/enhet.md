# SparkFun LilyPad USB — enhet

| Felt | Verdi |
|------|--------|
| Type | SparkFun LilyPad USB (ATmega32U4) |
| USB ID | `1b4f:9208` |
| Serial | `HIDFG` |
| Linux | `/dev/ttyACM0` (CDC ACM) + HID keyboard/mouse |
| Baud (seriell) | typisk 115200 |
| Arduino board | **LilyPad Arduino USB** / `lilypadusb` |
| MCU | ATmega32U4 @ 8 MHz, 3.3 V |

## Viktig

- Dette er **ikke** Hak5 Rubber Ducky. Ingen SD-kort, ingen `inject.bin` du kan lese som filer.
- Det som «ligger inne» er **én** kompilerte Arduino-sketch i flash. Ny flash overskriver den gamle.
- Duckyscript må konverteres til Arduino (`Keyboard` / `Mouse`) eller skrives direkte som `.ino`.
- Bruk **kun på egne maskiner / lab**. Ikke mot andres PC uten samtykke.

## Kobling Omarchy

```bash
# Tilgang til seriell (én gang)
sudo usermod -aG dialout "$USER"   # logg ut/inn etterpå
ls -l /dev/ttyACM0
```

## Flash

```bash
# Med arduino-cli (når installert)
arduino-cli board list
arduino-cli compile -b arduino:avr:lilypadusb sketches/demo-hello
arduino-cli upload -b arduino:avr:lilypadusb -p /dev/ttyACM0 sketches/demo-hello
```

Reset til bootloader: dobbelttrykk reset-knapp raskt (hvis LilyPad har synlig reset), eller bare upload mens porten er åpen.
