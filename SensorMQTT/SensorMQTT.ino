#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

#define PIR_PIN 7


byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 15, 10);
IPAddress server(192, 168, 15, 8);
int pinPIR = 7;

EthernetClient ethClient;
PubSubClient client;

void callback(char* topic, byte* payload, unsigned int length) {
  // Lógica para manipular mensagens recebidas do MQTT, se necessário
  if (payload[0] == '1') {
    if (digitalRead(pinPIR) == HIGH) {
      Serial.println("Detectado Movimento");
      delay(5000);
    }
    client.publish("outTopic", "Movimento");
  }
  if (payload[0] == '0') {
    if (digitalRead(pinPIR) != HIGH) {
      Serial.println("Não Detectado");
      delay(5000);
    }
    client.publish("outTopic", "Sem Movimento");
  }
}

void setup() {
  pinMode(pinPIR, INPUT);
  Serial.begin(9600);
  
  Ethernet.begin(mac, ip);
  client.setClient(ethClient);
  client.setServer(server, 1883);
  client.setCallback(callback);

  if (client.connect("arduinoClient")) {
    client.publish("outTopic", "Hello World");
    client.subscribe("inTopic");
  }
}

void loop() {
  client.loop();
}
