#include <Servo.h>
Servo SERVO_MOTOR;
int TIME;

void setup() {
  SERVO_MOTOR.attach(9);
  TIME = 10;
}
void loop() {
  SERVO_MOTOR.write(calculateValue());
  delay(TIME);
}

int calculateValue() {
  return map(analogRead(A0), 0, 1023, 0, 180);
}
