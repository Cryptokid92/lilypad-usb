// Generated from catalog.json
// mr-robot-exit: Mr Robot exit
// Source: inspired by Hak5 mr-robot_eXit
#include <Keyboard.h>

void setup() {
  delay(2000);
  Keyboard.begin();
  delay(200);
  Keyboard.println("Hello, friend.");
  delay(500);
  Keyboard.println("Control is an illusion.");
  Keyboard.println("eXit");
  Keyboard.println("# please enjoy your evening");
  delay(100);
  Keyboard.end();
}

void loop() {}
