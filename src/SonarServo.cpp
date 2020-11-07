#include "SonarServo.h"

SonarServo::SonarServo(int servoPin, Ultrasonic *sonar)
{
    _sonar = sonar;
    _servo.attach(servoPin);
}

void SonarServo::setup()
{
    _servo.write(90);
}

long SonarServo::distance()
{
//    return 0;
    return _sonar->Ranging(1);
}

void SonarServo::Angle(int angle)
{
    _currentServoAngle = angle;
    _servo.write(angle);
}
