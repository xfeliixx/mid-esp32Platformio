#include <analogWrite.h>
#define ONBOARD_LED  2
#define GREEN_LED 18
#define RED_LED 19
 
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
}
 
void loop() {
  delay(400);
  digitalWrite(LED_BUILTIN,0);
   digitalWrite(GREEN_LED,LOW);
  digitalWrite(RED_LED,HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN,10);
  digitalWrite(GREEN_LED,HIGH);
     digitalWrite(RED_LED,LOW);
}
