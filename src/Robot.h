
#ifndef Robot_h
#define Robot_h
#include"SonarServo.h"
#include"Motor.h"

class Robot{
  public:
    Robot(Motor *right, Motor *left, SonarServo *sonarServo);

    void Forward(int v = 255);
    void Backward(int v = 255);
    void Left(int v = 255);
    void Right(int v = 255);

    
    void motorTest(int sppedStart, int speedStep);
    void setup();
    void Stop();
    long distance();
    void debug(bool d = true);
  
  private:
    int _currentState;
    bool _debug;
    
    Motor *_leftMotor;
    Motor *_rightMotor;
    
    SonarServo *_sonarServo;
};
#endif
