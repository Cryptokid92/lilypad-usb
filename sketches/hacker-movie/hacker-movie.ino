// Generated from catalog.json
#include <Keyboard.h>

void setup() {
  delay(2400);
  Keyboard.begin();
  delay(200);
  Keyboard.press(KEY_LEFT_GUI);
  delay(30);
  Keyboard.press('1');
  delay(40);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("echo ACCESSING MAINFRAME");
  delay(300);
  Keyboard.println("echo bypassing nothing this is your pc");
  delay(300);
  Keyboard.println("echo download complete of zero bytes");
  delay(300);
  Keyboard.println("echo hack complete have a snack");
  delay(100);
  Keyboard.end();
}

void loop() {}
