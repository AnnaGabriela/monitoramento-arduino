void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Waiting for connection");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  
  Serial.println("");
}

void sendInfo(String endpoint, String parameters) {
    if (WiFi.status() == WL_CONNECTED) {
   
     HTTPClient http;
   
     http.begin(endpoint);
     http.addHeader("Content-Type", "application/x-www-form-urlencoded");
   
     int httpCode = http.POST(parameters);
     String payload = http.getString();
     
     Serial.print("Status Code: ");
     Serial.print(httpCode);
     Serial.print(" | Payload: ");
     Serial.println(payload);
   
     http.end();
   } else {
      Serial.println("Error in WiFi connection");   
   }
}

void setCupula() {
    String parameter_key = "name=";
    String parameter = parameter_key + CUPULA_NOME;
    sendInfo(ENDPOINT_CUPULAS, parameter);
}

void setAttribute(String attribute, float valueReceived) {
    String key_name = "attribute=";
    String key = key_name + attribute;
    String value_name = "&value=";
    String value = value_name + valueReceived;
    String parameter = key + value;
    sendInfo(ENDPOINT_CUPULA, parameter);
}
