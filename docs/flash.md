# Flash ny sketch til LilyPad USB

## 1. Én gangs oppsett (Omarchy)

```bash
# Verktøy
sudo pacman -S --needed arduino-cli

# Seriell-tilgang (logg ut/inn eller newgrp etterpå)
sudo usermod -aG dialout "$USER"
newgrp dialout   # eller logg ut/inn

# Arduino AVR-kjerne (LilyPad USB = ATmega32U4)
arduino-cli config init 2>/dev/null || true
arduino-cli core update-index
arduino-cli core install arduino:avr
```

Sjekk at enheten ses:

```bash
arduino-cli board list
# forvent /dev/ttyACM0 … SparkFun / LilyPad / 32u4
```

## 2. Skriv / rediger sketch

Eksempel ligger i:

`~/.local/share/lilypad-usb/sketches/demo-hello/demo-hello.ino`

Ny sketch: mappe med **samme navn** som `.ino`-fila:

```text
sketches/min-payload/
  min-payload.ino
```

## 3. Kompiler + last opp

Board FQBN for LilyPad USB:

`arduino:avr:LilyPadUSB`

```bash
PORT=/dev/ttyACM0
BOARD=arduino:avr:LilyPadUSB
SKETCH=~/.local/share/lilypad-usb/sketches/demo-hello

arduino-cli compile -b "$BOARD" "$SKETCH"
arduino-cli upload  -b "$BOARD" -p "$PORT" "$SKETCH"
```

Eller bruk hjelpescriptet:

```bash
~/.local/share/lilypad-usb/tools/flash.sh demo-hello
```

## 4. Hvis upload feiler

1. Plugg ut/inn LilyPad  
2. Hold **reset** (hvis den har) / dobbelttrykk reset for bootloader (LED blinker)  
3. Kjør `upload` innen ~8 sekunder  
4. Prøv `arduino-cli board list` på nytt — porten kan skifte til annen `ttyACM*`

## 5. Test

Åpne en **tom teksteditor**, plugg inn (eller trykk reset). Etter ~2 s skal demo-hello skrive en linje.
