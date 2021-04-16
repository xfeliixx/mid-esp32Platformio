#include <analogWrite.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define ONBOARD_LED  2
#define GREEN_LED 18
#define RED_LED 19

const char* mqtt_server = "mid.uber.space";
#define mqtt_port 47942
#define MQTT_USER "tut20"
#define MQTT_PASSWORD "nzeJgfnjMrXKi7J6fzUt"

const char* ssid = "Unser WLAN";
const char* password = "Bick31A_6591";

#define MQTT_SUB1 "ledan"
#define MQTT_SUB2 "ledaus"

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void callback(char* topic, byte *payload, unsigned int length) {
  Serial.println("-------new message from broker-----");
  Serial.print("channel:");
  Serial.println(topic);
  Serial.print("data:");
  Serial.write(payload, length);
  Serial.println();
}

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);

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

	client.setServer(mqtt_server, mqtt_port);
	client.setCallback(callback);

	while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "Felix";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(),MQTT_USER,MQTT_PASSWORD)) {
      Serial.println("connected");
      //Once connected, publish an announcement...
      client.publish("hello/FelixsBord", "It Works");
      // ... and resubscribe
      client.subscribe(MQTT_SUB1);
      client.subscribe(MQTT_SUB2);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
	client.loop();

}
