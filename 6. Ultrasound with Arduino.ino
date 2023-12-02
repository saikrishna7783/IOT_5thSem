const int pingPin = 7;
const int echoPin = 6;  // Trigger Pin of Ultrasonic Sensor const int echoPin = 6; // Echo Pin ofUltrasonic Sensor 

void setup() {
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, inches, cm;
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  Serial.print(inches);
  Serial.print("inches");
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.println("cm");
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
