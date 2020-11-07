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

void SonarServo::scan()
{
  int stepWait = 30;
  int stepAngle = 5;
  int i;
  for (i=90; i >= 0; i -= stepAngle) {
    oneScan(i, stepWait);
  }
  
  for (i=0; i < 180; i += stepAngle) {
    oneScan(i, stepWait);
  }
  
  for (i=180; i >= 90; i -= stepAngle) {
    oneScan(i, stepWait);
  }

//  delay(100);
  this->Angle(90);
}

void SonarServo::oneScan(int angle, int wait)
{
    this->Angle(angle);
    this->distance();
    delay(wait);
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
