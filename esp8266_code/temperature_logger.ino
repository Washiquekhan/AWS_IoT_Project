#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

const char* mqtt_server = "YOUR_AWS_ENDPOINT";
const int mqtt_port = 8883;

const char* certificate_pem_crt = "-----BEGIN CERTIFICATE-----\nYOUR_CERTIFICATE\n-----END CERTIFICATE-----\n";
const char* private_pem_key = "-----BEGIN PRIVATE KEY-----\nYOUR_PRIVATE_KEY\n-----END PRIVATE KEY-----\n";
const char* root_ca = "-----BEGIN CERTIFICATE-----\nYOUR_AWS_ROOT_CA\n-----END CERTIFICATE-----\n";

WiFiClientSecure espClient;
PubSubClient client(espClient);

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void reconnect() {
  while (!client.connected()) {
    client.connect("ESP8266Client");
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  espClient.setCACert(root_ca);
  espClient.setCertificate(certificate_pem_crt);
  espClient.setPrivateKey(private_pem_key);
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();
  
  float temperature = dht.readTemperature();
  String payload = String("{\"temperature\":") + temperature + "}";
  client.publish("home/temperature", payload.c_str());
  delay(5000);
}
