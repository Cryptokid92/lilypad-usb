// Generated from catalog.json
// hypr-cheat: Hypr cheat sheet
#include <Keyboard.h>

void setup() {
  delay(2300);
  Keyboard.begin();
  delay(200);
  Keyboard.press(KEY_LEFT_GUI);
  delay(30);
  Keyboard.press('1');
  delay(40);
  Keyboard.releaseAll();
  delay(900);
  Keyboard.println("echo Super 1 is foot");
  delay(200);
  Keyboard.println("echo Super 3 is the browser");
  delay(200);
  Keyboard.println("echo green means you are home");
  delay(100);
  Keyboard.end();
}

void loop() {}
