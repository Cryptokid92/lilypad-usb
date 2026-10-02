// Generated from catalog.json
// love-omarchy: Love letter
#include <Keyboard.h>

void setup() {
  delay(1900);
  Keyboard.begin();
  delay(200);
  Keyboard.press(KEY_LEFT_GUI);
  delay(30);
  Keyboard.press('1');
  delay(40);
  Keyboard.releaseAll();
  delay(800);
  Keyboard.println("echo dear omarchy");
  delay(200);
  Keyboard.println("echo black background phosphor letters");
  delay(200);
  Keyboard.println("echo foot on super 1 feels like home");
  delay(200);
  Keyboard.println("echo love cryptokid");
  delay(100);
  Keyboard.end();
}

void loop() {}
