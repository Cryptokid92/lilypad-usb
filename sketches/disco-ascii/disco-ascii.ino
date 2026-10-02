// Generated from catalog.json
// disco-ascii: Disco letters
#include <Keyboard.h>

void setup() {
  delay(1800);
  Keyboard.begin();
  delay(200);
  Keyboard.println("DISCO");
  Keyboard.println("o  o  o  o");
  Keyboard.println("  PARTY TIME");
  Keyboard.println("o  o  o  o");
  Keyboard.println("cryptokid on the floor");
  delay(100);
  Keyboard.end();
}

void loop() {}
