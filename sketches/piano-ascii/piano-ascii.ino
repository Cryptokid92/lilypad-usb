// Generated from catalog.json
// piano-ascii: Piano ascii
// Source: inspired by Hak5 Piano_Player
#include <Keyboard.h>

void setup() {
  delay(1800);
  Keyboard.begin();
  delay(200);
  Keyboard.println("C D E F G A B C");
  Keyboard.println("| | | | | | | |");
  Keyboard.println("do re mi fa so la ti do");
  Keyboard.println("(imaginary concert)");
  delay(100);
  Keyboard.end();
}

void loop() {}
