// Generated from catalog.json
// matrix-wake-up: Matrix wake up
// Source: inspired by Hak5 The_Matrix-Wake_Up / Digital_Rain
#include <Keyboard.h>

void setup() {
  delay(2000);
  Keyboard.begin();
  delay(200);
  Keyboard.println("Wake up, Neo...");
  delay(400);
  Keyboard.println("The Matrix has you...");
  delay(400);
  Keyboard.println("Follow the white rabbit.");
  Keyboard.println("knock knock");
  Keyboard.println("# omarchy matrix mode");
  delay(100);
  Keyboard.end();
}

void loop() {}
