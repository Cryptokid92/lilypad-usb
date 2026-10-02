// Generated from catalog.json
#include <Keyboard.h>

void setup() {
  delay(1600);
  Keyboard.begin();
  delay(200);
  Keyboard.press(KEY_LEFT_GUI);
  delay(30);
  Keyboard.press('1');
  delay(40);
  Keyboard.releaseAll();
  delay(900);
  Keyboard.println("neofetch || fastfetch || uname -a");
  delay(100);
  Keyboard.end();
}

void loop() {}
