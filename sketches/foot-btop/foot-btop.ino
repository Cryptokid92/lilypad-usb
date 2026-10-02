// Generated from catalog.json
// foot-btop: Foot then btop
#include <Keyboard.h>

void setup() {
  delay(1800);
  Keyboard.begin();
  delay(200);
  Keyboard.press(KEY_LEFT_GUI);
  delay(30);
  Keyboard.press('1');
  delay(40);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("btop");
  delay(100);
  Keyboard.end();
}

void loop() {}
