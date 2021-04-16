#include <analogWrite.h>
#include <ezButton.h>

ezButton button(4);

#define greenLED 18
#define redLED 19

boolean showLed = false;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  button.setDebounceTime(20);
  Serial.begin(115200);

}

void loop() {
//Print Button
  button.loop();
  int presses = button.getCount();
  Serial.println(presses);

//check for Button presses
  if (button.isPressed()) {
    showLed = !showLed;
  }


  if (showLed) {
  //Fade LED
    Serial.println(brightness);
     analogWrite(greenLED, brightness);
     analogWrite(redLED, LOW);

       brightness = brightness + fadeAmount;

       // reverse the direction of the fading at the ends of the fade:
       if (brightness <= 0 || brightness >= 255) {
       fadeAmount = -fadeAmount;
       }

    delay(30);

  } else {
    //Freeze green
    analogWrite(greenLED, brightness);
     analogWrite(redLED, 255);
  }

}
