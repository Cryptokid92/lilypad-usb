/*
 * demo-hello — LilyPad USB
 * Venter 2s, skriver en linje. Åpne en tom editor først.
 */
#include <Keyboard.h>

void setup() {
  delay(2000);
  Keyboard.begin();
  delay(200);
  Keyboard.println("lilypad-usb demo-hello ok");
  Keyboard.end();
}

void loop() {}
