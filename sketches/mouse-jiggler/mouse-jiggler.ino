// Generated from catalog.json
// mouse-jiggler: Mouse jiggler
// Source: inspired by Flipper Mouse jiggler / Hak5 The_Mouse_Moves_By_Itself / FP jiggler.txt
#include <Keyboard.h>
#include <Mouse.h>

void setup() {
  delay(1500);
  Keyboard.begin();
  Mouse.begin();
  delay(200);
  Mouse.move(8, 0);
  delay(200);
  Mouse.move(-8, 0);
  delay(200);
  Mouse.move(0, 8);
  delay(200);
  Mouse.move(0, -8);
  Mouse.move(5, 5);
  Mouse.move(-5, -5);
  delay(100);
  Keyboard.end();
  Mouse.end();
}

void loop() {}
