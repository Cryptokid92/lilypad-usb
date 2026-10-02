// Generated from catalog.json
#include <Keyboard.h>

void setup() {
  delay(2100);
  Keyboard.begin();
  delay(200);
  Keyboard.println("3");
  delay(400);
  Keyboard.println("2");
  delay(400);
  Keyboard.println("1");
  delay(400);
  Keyboard.println("just kidding have a nice day");
  delay(100);
  Keyboard.end();
}

void loop() {}
