// C++ code
//
#include <Servo.h>

int drive = 0;

int distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_2;

void setup()
{
  Serial.begin(9600);
  servo_2.attach(2, 500, 2500);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  distance = 0.01723 * readUltrasonicDistance(12, 10);
  Serial.print(distance);
  Serial.println("cm");
  if (distance < 10) {
    servo_2.write(90);
    Serial.println("reverse");
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    Serial.println("left");
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
  } else {
    servo_2.write(0);
    Serial.println("forward");
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}