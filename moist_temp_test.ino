  const int moistPin = A0;
  const int tempPin = A1;

  const int AirValue = 620;   //you need to replace this value with Value_1
  const int WaterValue = 310;  //you need to replace this value with Value_2
  int soilMoistureValue = 0;
  int soilMoisturePercent=0;

  int temperatureValue = 0;

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}

void loop() {
  //finding moisture level
  soilMoistureValue = analogRead(moistPin);  //put Sensor insert into soil
  Serial.println(soilMoistureValue);
  soilMoisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilMoisturePercent >= 100)
  {
    Serial.println("100 %");
  }
  else if(soilMoisturePercent <=0)
  {
    Serial.println("0 %");
  }
  else if(soilMoisturePercent >0 && soilMoisturePercent < 100)
  {
    Serial.print(soilMoisturePercent);
    Serial.println("%");
  }

  //finding temperature
  temperatureValue = analogRead(tempPin);
  Serial.print(temperatureValue);
  Serial.println(" temperature value");
  
  
  delay(1000);
}
