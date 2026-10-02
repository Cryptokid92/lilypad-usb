// Generated from catalog.json
// keyboard-cat: Keyboard cat
#include <Keyboard.h>

void setup() {
  delay(1600);
  Keyboard.begin();
  delay(200);
  Keyboard.println("meow meow tap tap");
  delay(200);
  Keyboard.println("meow");
  delay(200);
  Keyboard.println("purr");
  delay(100);
  Keyboard.end();
}

void loop() {}
