// Generated from catalog.json
// pomodoro-ping: Pomodoro ping
// Source: inspired by Flipper Flipp Pomodoro (awesome-flipperzero)
#include <Keyboard.h>

void setup() {
  delay(1700);
  Keyboard.begin();
  delay(200);
  Keyboard.println("POMODORO START");
  Keyboard.println("25 minutes. Phone down.");
  Keyboard.println("Then coffee. Then glory.");
  delay(100);
  Keyboard.end();
}

void loop() {}
