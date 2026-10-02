// Generated from catalog.json
// catch-me: Try to catch me
// Source: inspired by Hak5 Try_To_Catch_Me
#include <Keyboard.h>
#include <Mouse.h>

void setup() {
  delay(1500);
  Keyboard.begin();
  Mouse.begin();
  delay(200);
  Mouse.move(40, 0);
  delay(150);
  Mouse.move(0, 40);
  delay(150);
  Mouse.move(-40, 0);
  delay(150);
  Mouse.move(0, -40);
  Mouse.move(20, -10);
  delay(100);
  Keyboard.end();
  Mouse.end();
}

void loop() {}
