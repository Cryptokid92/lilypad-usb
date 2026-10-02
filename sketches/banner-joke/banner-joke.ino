// Generated from catalog.json
// banner-joke: Banner joke
// Source: inspired by Hak5 Full-ScreenBannerJoke
#include <Keyboard.h>

void setup() {
  delay(1800);
  Keyboard.begin();
  delay(200);
  Keyboard.println("##############################");
  Keyboard.println("#   IMPORTANT SYSTEM NOTE   #");
  Keyboard.println("#   you are doing great     #");
  Keyboard.println("##############################");
  delay(100);
  Keyboard.end();
}

void loop() {}
