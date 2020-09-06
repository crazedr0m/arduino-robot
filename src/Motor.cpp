#include"Motor.h"
#include"Arduino.h"

Motor::Motor(int forwardPin,int backwardPin, int speedPin){
  _forwardPin = forwardPin;
  _backwardPin = backwardPin;
  _speedPin = speedPin;
  _currentState = 0;
  
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
    
  analogWrite(_speedPin, s);
}
void Motor::Backward(int s=255){
  if (_currentState != -1) {
    analogWrite(_speedPin, 0);
    digitalWrite(_forwardPin, LOW);
    digitalWrite(_backwardPin, HIGH);
    _currentState = -1;
  }
  
  analogWrite(_speedPin, s);
}
void Motor::Stop(){
  
  digitalWrite(_forwardPin, LOW);
  digitalWrite(_backwardPin, LOW);
  _currentState = 0;
  analogWrite(_speedPin, 0);
}
