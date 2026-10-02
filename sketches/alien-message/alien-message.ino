// Generated from catalog.json
// alien-message: Alien message
// Source: inspired by Hak5 Alien Message From Computer
#include <Keyboard.h>

void setup() {
  delay(2000);
  Keyboard.begin();
  delay(200);
  Keyboard.println(">>> INCOMING TRANSMISSION <<<");
  Keyboard.println("GREETINGS EARTHLING");
  Keyboard.println("BRING SNACKS TO SECTOR 7G");
  Keyboard.println("END OF MESSAGE");
  delay(100);
  Keyboard.end();
}

void loop() {}
