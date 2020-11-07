#ifndef SonarServo_h
#define SonarServo_h

#include <Ultrasonic.h>
#include <Servo.h>

class SonarServo{
  public:
    SonarServo(int servoPin, Ultrasonic *sonar);
    
    void Angle(int angle);
    long distance();
    void setup();
  
  private:

    int _currentServoAngle;
    Ultrasonic *_sonar;
    Servo _servo;
};
#endif