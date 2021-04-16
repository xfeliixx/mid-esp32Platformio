#include <ezButton.h>

ezButton button(4);
#define SLIDER1_PIN 27
#define SLIDER2_PIN 26
#define SLIDER3_PIN 25
#define SLIDER4_PIN 33
  int activeSlider = 0;

void setup() {
  Serial.begin(115200); // Schnelle und gängige Baudrate
  button.setDebounceTime(20); // Wenn zu hoch, werden keine schnellen Drücker mehr erkannt.
}

void loop() {
button.loop(); // Muss pro Button hier sein

  int slider1_val = analogRead(SLIDER1_PIN);
  int slider2_val = analogRead(SLIDER2_PIN);
  int slider3_val = analogRead(SLIDER3_PIN);
  int slider4_val = analogRead(SLIDER4_PIN);

if (button.isPressed()) {
  Serial.print("Pressed: ");
	activeSlider++;
	if(activeSlider > 3) {
	activeSlider = 1;

	}
}
  Serial.print("Active Slider: ");
  Serial.println(activeSlider);

if (activeSlider == 1) {
  Serial.print("Slider 1: ");
  Serial.println(slider1_val);
}
if (activeSlider == 2) {
    Serial.print("Slider 2: ");
    Serial.println(slider2_val);
}
if (activeSlider == 3) {
    Serial.print("Slider 3: ");
    Serial.println(slider3_val);
}
if (activeSlider == 4) {
    Serial.print("Slider 4: ");
    Serial.println(slider4_val);
}
}
