#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor{
  public:
    Motor(int forwardPin, int backwardPin, int speedPin);
    void Forward(int v = 255);
    void Backward(int v = 255);
    void setup();
    void Stop();
    void debug(bool d = true);
    void test(int speedStart, int speedTest);
  
  private:
    bool _debug;
    int _forwardPin;
    int _backwardPin;
    int _speedPin;
    int _currentState;
};
#endif
