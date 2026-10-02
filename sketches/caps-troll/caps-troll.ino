// Generated from catalog.json
// caps-troll: Caps lock troll
// Source: inspired by Hak5 cApS-Troll
#include <Keyboard.h>

void setup() {
  delay(1500);
  Keyboard.begin();
  delay(200);
  Keyboard.write(KEY_CAPS_LOCK);
  delay(200);
  Keyboard.println("WHY IS EVERYTHING LOUD");
  delay(400);
  Keyboard.write(KEY_CAPS_LOCK);
  Keyboard.println("ok caps is back to normal");
  delay(100);
  Keyboard.end();
}

void loop() {}
