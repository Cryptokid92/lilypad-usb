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
  Keyboard.println("echo proxmox guests are napping");
  delay(250);
  Keyboard.println("echo opnsense keeps the home gate");
  delay(250);
  Keyboard.println("echo homarr still has the tiles");
  delay(250);
  Keyboard.println("echo this sketch stores nothing sensitive");
  delay(100);
  Keyboard.end();
}

void loop() {}
