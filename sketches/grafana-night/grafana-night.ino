// Generated from catalog.json
// grafana-night: Grafana night
#include <Keyboard.h>

void setup() {
  delay(2100);
  Keyboard.begin();
  delay(200);
  Keyboard.press(KEY_LEFT_GUI);
  delay(30);
  Keyboard.press('1');
  delay(40);
  Keyboard.releaseAll();
  delay(1200);
  Keyboard.println("xdg-open http://192.168.50.155:3001/d/infra-night-mode");
  delay(100);
  Keyboard.end();
}

void loop() {}
