
#include <WiFi.h>

const char* ssid = "Unser WLAN";
const char* password = "Bick31A_6591";

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);
	Serial.print("Connecting to ssid: ");
	Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");
  	Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop () {
}
