// Generated from catalog.json
// terminal-spam: Terminal spam
// Source: inspired by Hak5 Continuos Print In Terminal / Windows-Spam-Terminals
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
  Keyboard.println("echo QUACK");
  Keyboard.println("echo QUACK AGAIN");
  Keyboard.println("echo ok that is enough quacking");
  delay(100);
  Keyboard.end();
}

void loop() {}
