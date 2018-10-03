float getTemperature() {
  Vo = analogRead(temperaturaPin);

  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  temp = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  temp = temp - 273.15;
  temp = temp * -1.0;
  Serial.println("Temperatura:");
  Serial.println(temp);
  setAttribute("temperatura", temp);
}

//void getUmidade() {
//  float value = 22;
//  setAttribute("umidade", value);
//}

/*float getLuminosidade() {
  float value = (analogRead(LuxPin)*39.0625);
  setAttribute("luminosidade", value);

  return value
}*/
