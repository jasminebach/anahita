#include <Servo.h>

int set = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

Servo servo_8;
void setup()
{
  servo_8.attach(8, 500, 2500);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  long duration = readUltrasonicDistance(6, 5);

  float distance = duration / 2.0 / 29.1;

  if (distance < 10) {
    servo_8.write(90);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(5000);
  } else {
    servo_8.write(0);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }
}

