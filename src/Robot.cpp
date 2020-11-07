#include"Robot.h"
#include"Arduino.h"

Robot::Robot(Motor *right, Motor *left, SonarServo *sonarServo){
  _rightMotor = right;
  _leftMotor = left;
  _sonarServo = sonarServo;
}

void Robot::debug(bool d = true)
{
  _debug = d;
  _rightMotor->debug(d);
  _leftMotor->debug(d);
}

long Robot::distance()
{
  long distance;
  
  distance = _sonarServo->distance();
  Serial.print("distance: ");
  Serial.println(distance);
}
  
void Robot::setup()
{
  if (_debug) {
    Serial.println("Robot setup");
  }
  _rightMotor->setup();
  _leftMotor->setup();
}

void Robot::Left(int s = 255){
  _rightMotor->Forward(s);
  _leftMotor->Backward(s);
}

void Robot::Right(int s = 255){
  _rightMotor->Backward(s);
  _leftMotor->Forward(s);
}

void Robot::Forward(int s=255){
  _rightMotor->Forward(s);
  _leftMotor->Forward(s);
}

void Robot::Backward(int s=255){
  _rightMotor->Backward(s);
  _leftMotor->Backward(s);
}

void Robot::motorTest(int speedStart, int speedStep)
{
  if (_debug) {
    Serial.println("right motor test");
  }
  _rightMotor->test(speedStart, speedStep);
  
  if (_debug) {
    Serial.println("left motor test");
  }
  _leftMotor->test(speedStart, speedStep);
}

void Robot::Stop(){
  
  if (_debug) {
    Serial.println("right motor stop");
  }
  _rightMotor->Stop();
  
  if (_debug) {
    Serial.println("left motor stop");
  }
  _leftMotor->Stop();
}
