// Generated from catalog.json
// yt-tripwire-lite: YouTube open
// Source: inspired by Hak5 / Jakoby YT-Tripwire (harmless open only)
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
  Keyboard.println("xdg-open https://www.youtube.com/");
  delay(100);
  Keyboard.end();
}

void loop() {}
