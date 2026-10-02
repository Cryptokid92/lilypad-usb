// Generated from catalog.json
// quack-roll: Quack rolled
// Source: inspired by Hak5 Quack_Rolled / YouHaveBeenQuacked2.0
#include <Keyboard.h>

void setup() {
  delay(1700);
  Keyboard.begin();
  delay(200);
  Keyboard.println("  __");
  Keyboard.println("<(o )___");
  Keyboard.println(" ( ._> /");
  Keyboard.println("  `---'  QUACK");
  Keyboard.println("you have been quacked (nicely)");
  delay(100);
  Keyboard.end();
}

void loop() {}
