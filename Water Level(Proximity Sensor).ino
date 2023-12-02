#include <NewPing.h>
#define TRIGGER_PIN 12    // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 11       // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200  // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

simon::NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);  // NewPing setup of pins and maximum distance.
int tonepin = 8;
int distance;

void setup() {
  Serial.begin(9600);  // Open serial monitor at 115200 baud to see ping results.
  pinMode(tonepin, OUTPUT);
}

void loop() {
  delay(500);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping();  // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  distance = uS / US_ROUNDTRIP_CM;

  Serial.print(distance);  // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  if (distance > 0 && distance < 10) {
    Serial.print("Less Distance");
    tone(tonepin, 2000, 1000);
  }

  if (distance > 10) {
    noTone(8);
  }
}
