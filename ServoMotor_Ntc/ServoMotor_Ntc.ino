#include <Servo.h>
Servo SERVO_MOTOR;

void setup() {
  SERVO_MOTOR.attach(9);
}
void loop() {
  SERVO_MOTOR.write(calculateValue());
  delay(analogRead(A0)); // Potansiyometre
}

int calculateValue() {
  return map(analogRead(A2), 0, 1023, 0, 180); // NTC
}
