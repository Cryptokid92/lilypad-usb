// Generated from catalog.json
// rickroll-ascii: ASCII rickroll
// Source: inspired by Hak5 RickRoll_ASCII / TerminalRickRoll
#include <Keyboard.h>

void setup() {
  delay(1800);
  Keyboard.begin();
  delay(200);
  Keyboard.println("Never gonna give you up");
  Keyboard.println("Never gonna let you down");
  Keyboard.println("Never gonna run around and desert you");
  Keyboard.println("(ascii edition, own screen only)");
  delay(100);
  Keyboard.end();
}

void loop() {}
