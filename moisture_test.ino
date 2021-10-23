const int moistPin = A0;

const int AirValue = 438;   //you need to replace this value with Value_1
const int WaterValue = 208;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilMoisturePercent=0;



void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}

void loop() {
  //finding moisture level
  soilMoistureValue = analogRead(moistPin);  //put Sensor insert into soil
  //Serial.println(soilMoistureValue);
  soilMoisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

  Serial.print("water is: ");
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

  delay(1000);
}
