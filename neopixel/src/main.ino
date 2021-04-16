#include <Adafruit_NeoPixel.h>


#define NEOLED_PIN 27
#define LED_COUNT 1

Adafruit_NeoPixel neo(LED_COUNT, NEOLED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  pinMode(LED_BUILTIN,OUTPUT);


  neo.begin();
  neo.show(); //Pixels off at start
}

void loop() {


//int r = 0;
//int b = 200;
//for (int i=0;i<200; i++) {
//r++;
//b--;
//neo.setPixelColor(0,r, 0, b);
  //neo.show();
  //delay(100);
    //Serial.println("<Hey");
//}
  neo.setPixelColor(0,100,0,100);
  neo.show();
}
