#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID          "Visitante_L.O.U.Co"
#define WIFI_PASSWORD      "bemvindoaolouco"

const String ENDPOINT_CUPULAS = "http://ecodomo-api.herokuapp.com/cupulas";
const String CUPULA_NOME = "louco";
String slash = "/";
const String ENDPOINT_CUPULA = ENDPOINT_CUPULAS + slash + CUPULA_NOME;

int temperaturaPin = A0;
int Vo;
float R1 = 10000;
float logR2, R2, temp;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;


void setup() {
  Serial.begin(115200);
  connectToWiFi();
  setCupula();
}

void loop() {
  getTemperature();
  delay(1000000);
}
