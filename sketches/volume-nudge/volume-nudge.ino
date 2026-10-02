// Generated from catalog.json
// volume-nudge: Volume nudge
// Source: inspired by Hak5 MaxVolumeRickroll_Windows / SoundChangeDuck
#include <Keyboard.h>

void setup() {
  delay(1800);
  Keyboard.begin();
  delay(200);
  Keyboard.press(KEY_LEFT_GUI);
  delay(30);
  Keyboard.press('1');
  delay(40);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+ || pactl set-sink-volume @DEFAULT_SINK@ +5%");
  delay(100);
  Keyboard.end();
}

void loop() {}
