// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// ---------------------------------------------------------------- //

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
}
void loop() {
  // Calculating the distance
  distance = getDistance(echoPin, trigPin);
  
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(50);
}

//Returns Ultra Sonic Sensor reading in CM
float getDistance(int ECHO, int TRIG){
  
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  
  //Ultra-Sonic Input
  digitalWrite(TRIG, LOW);
  delay(10);
  digitalWrite(TRIG, HIGH);
  delay(10);
  digitalWrite(TRIG, LOW);

  float duration = pulseIn(ECHO, HIGH);
  duration += 40;
  
  float distance = (duration/2) * 343.42 * 0.0001;

  return distance;
}
