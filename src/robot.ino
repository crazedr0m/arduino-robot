#include "Robot.h"

int MotorLeftSpeed = 11; // Левый (А) мотор СКОРОСТЬ — ENA
int MotorLeftForward = 10; // Левый (А) мотор ВПЕРЕД — IN1
int MotorLeftBack = 9; // Левый (А) мотор НАЗАД — IN2

int MotorRightForward = 8; // Правый (В) мотор ВПЕРЕД — IN3
int MotorRightBack = 7; // Правый (В) мотор НАЗАД — IN4
int MotorRightSpeed = 6; // Правый (В) мотор СКОРОСТЬ — ENB

int sonarTriger = 13; // Сонар тригер
int sonarEcho = 12; // Сонар эхо
int sonarServoPin = 5; // Серво привод для сонара

SonarServo sonarServo(sonarServoPin, sonarTriger, sonarEcho);

Motor motorRight(MotorRightForward, MotorRightBack, MotorRightSpeed);
Motor motorLeft(MotorLeftForward, MotorLeftBack, MotorLeftSpeed);

Robot robot(&motorRight, &motorLeft, &sonarServo);

void setup() {
    Serial.begin(115200);
    robot.debug();
    robot.setup();
    
    robot.Stop();
}

void loop() {

    sonarServo.scan();
    delay(800);
    
  robot.Forward();
  delay(1000);
  robot.Backward();
  delay(1000);
  robot.Right();
  delay(1000);
  robot.Left();
  delay(1000);
  robot.Stop();
}
