// Generated from catalog.json
// usb-scream: USB scream
// Source: inspired by Hak5 USBScream
#include <Keyboard.h>

void setup() {
  delay(1500);
  Keyboard.begin();
  delay(200);
  Keyboard.println("A");
  Keyboard.println("AA");
  Keyboard.println("AAA");
  Keyboard.println("AAAA");
  Keyboard.println("AAAAA");
  Keyboard.println("(internal scream complete)");
  delay(100);
  Keyboard.end();
}

void loop() {}
