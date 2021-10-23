#include "DHT.h"
#define DHTPIN 10     
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

// Pins
const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int ENA = 9;
const int ENB = 3;

const int moistPin = A0;

//variables for moisture
const int AirValue = 438;   
const int WaterValue = 208; 
int soilMoistureValue = 0;
int soilMoisturePercent=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  dht.begin();

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Getting most percentage
  int thresholdP = 70;
  int moistValue = moist();

  //Checking soil Moist Percentage
  if (moistValue > thresholdP){
    TurnLED(true);

    //Checking Sun Light Value
    if(IsLightOutside){
      
    }
  }
  else{
    TurnLED(false);
  }

  
  //OpenAndCloseMotor(5000);
  //EvaporationRate(30, 70);
  //float x = Humidity();
  delay(1000);
}

int moist(){


  soilMoistureValue = analogRead(moistPin);
  soilMoisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilMoisturePercent<=0){
    soilMoisturePercent = 0;
  }
  if(soilMoisturePercent>=100){
    soilMoisturePercent=100;
  }
  
  return soilMoisturePercent;
  
}


//Flash LED
void TurnLED(boolean onOrOff){

  if(onOrOff){
      digitalWrite(12, HIGH);
  }
  else{
      digitalWrite(12, LOW);
  }
}

//Checks Light Levels
boolean IsLightOutside(){
  
  //Check Light Value
  int value = analogRead(A0);
  Serial.println("Analog value : ");
  Serial.println(value);
  if(value > 250){
    return true;
  }
  return false;
}

//Checks Humidity Percentage
float Humidity(){
  float h = dht.readHumidity();
  
  if (isnan(h)){
    h = 70;
  }
  return h;
}

//Checks Temp in Celcius
float Temp(){
  float t = dht.readTemperature();
  if (isnan(t)){
    t = 23;
  }
  return t;
}

// Evaporation Formula
float EvaporationRate(int temp, float humidity){

  //Getting Water's Vapor Pressure (mmHG)
  float P = pow(2.718, 20.386-(5132/(273+temp)));
  //Area
  float A = 3;
  float W = 8*(1/(humidity/70));
  float E = (P*A*W)/(temp*9/5 + 32 + 459.67);
  float miliL = E*3.785411784/1440*1000;

  return miliL;
}


//Open and Close Motor
int OpenAndCloseMotor(int timeOpen){ 
    
    //Open Valve 
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    turnMotorOn();
    delay(1000);
    
    //Leave Valve Open
    turnMotorOff();
    delay(timeOpen);
    
    //Close Valve
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    turnMotorOn();
    delay(1000);

    turnMotorOff();
}
void turnMotorOn(){
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}
void turnMotorOff(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
