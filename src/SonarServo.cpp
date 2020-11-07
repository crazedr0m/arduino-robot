#include "SonarServo.h"

SonarServo::SonarServo(int servoPin, int trigerPin, int echoPin)
{
    _trigerPin = trigerPin;
    _echoPin = echoPin;
    _servoPin = servoPin;
}

void SonarServo::setup()
{
     Servo servo;
    _servo = &servo;
    
    Ultrasonic sonar(_trigerPin, _echoPin);
    _sonar = &sonar;
    _servo->attach(_servoPin);
    _servo->write(90);
}

long SonarServo::distance()
{
    return _sonar->Ranging(1);
}

void SonarServo::Angle(int angle)
{
    _currentServoAngle = angle;
    _servo->write(angle);
}
