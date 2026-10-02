// Generated from catalog.json
// star-lilypad-repo: Open own repo
// Source: inspired by FalsePhilosopher general/GitHub-Star.txt
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
  Keyboard.println("xdg-open https://github.com/Cryptokid92/lilypad-usb");
  delay(100);
  Keyboard.end();
}

void loop() {}
