#include"Motor.h"
#include"Arduino.h"

Motor::Motor(int forwardPin,int backwardPin, int speedPin){
  _forwardPin = forwardPin;
  _backwardPin = backwardPin;
  _speedPin = speedPin;
  _currentState = 0;
}

void Motor::debug(bool d = true)
{
  _debug = d;
}
  
void Motor::setup()
{

  if (_debug) {
    Serial.println("Motor setup");
  }

  pinMode(_forwardPin, OUTPUT);
  pinMode(_backwardPin, OUTPUT);
  pinMode(_speedPin, OUTPUT);

}

void Motor::Forward(int s=255){
  if (_currentState != 1) {
    analogWrite(_speedPin, 0);
    digitalWrite(_backwardPin, LOW);
    digitalWrite(_forwardPin, HIGH);
    _currentState = 1;
  }
  if (_debug) {
    Serial.print("Forward ");
    Serial.println(s);
  }
  analogWrite(_speedPin, s);
}
void Motor::Backward(int s=255){
  if (_currentState != 2) {
    analogWrite(_speedPin, 0);
    digitalWrite(_forwardPin, LOW);
    digitalWrite(_backwardPin, HIGH);
    _currentState = 2;
  }
  
  if (_debug) {
    Serial.print("Backward ");
    Serial.println(s);
  }
  
  analogWrite(_speedPin, s);
}

void Motor::test(int speedStart, int speedStep)
{
  int i;
  for (i = speedStart; i <= 255; i += speedStep) {
    Forward(i);
    delay (100);
  }
  
  for (i = speedStart; i <= 255; i += speedStep) {
    Backward(i);
    delay (100);
  }
}

void Motor::Stop(){
  analogWrite(_speedPin, 0);
  digitalWrite(_forwardPin, LOW);
  digitalWrite(_backwardPin, LOW);
  _currentState = 0;
}
