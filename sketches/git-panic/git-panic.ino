// Generated from catalog.json
#include <Keyboard.h>

void setup() {
  delay(2000);
  Keyboard.begin();
  delay(200);
  Keyboard.press(KEY_LEFT_GUI);
  delay(30);
  Keyboard.press('1');
  delay(40);
  Keyboard.releaseAll();
  delay(1100);
  Keyboard.println("cd");
  delay(300);
  Keyboard.println("git status");
  delay(100);
  Keyboard.end();
}

void loop() {}
