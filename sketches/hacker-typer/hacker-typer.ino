// Generated from catalog.json
// hacker-typer: Hacker typer
// Source: inspired by Hak5 Hacker_Typer
#include <Keyboard.h>

void setup() {
  delay(1600);
  Keyboard.begin();
  delay(200);
  Keyboard.println("ACCESSING MAINFRAME...");
  delay(300);
  Keyboard.println("DECRYPTING... 12%");
  Keyboard.println("DECRYPTING... 67%");
  Keyboard.println("DECRYPTING... 100%");
  Keyboard.println("FOUND: one (1) rubber duck");
  Keyboard.println("MISSION: make coffee");
  delay(100);
  Keyboard.end();
}

void loop() {}
