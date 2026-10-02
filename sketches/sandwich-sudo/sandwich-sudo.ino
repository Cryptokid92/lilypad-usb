// Generated from catalog.json
#include <Keyboard.h>

void setup() {
  delay(1700);
  Keyboard.begin();
  delay(200);
  Keyboard.press(KEY_LEFT_GUI);
  delay(30);
  Keyboard.press('1');
  delay(40);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("echo sudo make me a sandwich");
  delay(250);
  Keyboard.println("echo make says there is no target named me");
  delay(250);
  Keyboard.println("echo okay");
  delay(100);
  Keyboard.end();
}

void loop() {}
