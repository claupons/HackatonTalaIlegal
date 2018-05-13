#include<AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  motor1.setSpeed(1000);
  motor2.setSpeed(1000);
  motor3.setSpeed(1000);
  motor4.setSpeed(1000);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(1000);
}
