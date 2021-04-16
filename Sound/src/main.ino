#include <melody_player.h>
#include <melody_factory.h>

#define SPEAKER_PIN 14

MelodyPlayer player(SPEAKER_PIN);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  String notes[] = { "A4", "A4", "A4", "F4", "C5", "A4", "F4", "C5", "A4" };
  // Load and play a correct melody
    Melody melody = MelodyFactory.load("Star Wars", 500, notes, 9);

  player.play(melody);
  delay(1000);
	player.playAsync(melody); // Non-Blocking
}
void loop() {
}
