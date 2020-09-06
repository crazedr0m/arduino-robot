#include "Motor.h"


//int MotorLeftSpeed = 5; // Левый (А) мотор СКОРОСТЬ — ENA
//int MotorLeftForward = 4; // Левый (А) мотор ВПЕРЕД — IN1
//int MotorLeftBack = 2; // Левый (А) мотор НАЗАД — IN2
int MotorRightForward = 8; // Правый (В) мотор ВПЕРЕД — IN3
int MotorRightBack = 7; // Правый (В) мотор НАЗАД — IN4
int MotorRightSpeed = 9; // Правый (В) мотор СКОРОСТЬ — ENB
Motor motorRight(MotorRightForward, MotorRightBack, MotorRightSpeed);
void setup() {
//pinMode (MotorRightForward, OUTPUT);
//pinMode (MotorRightBack, OUTPUT);
//pinMode (MotorRightSpeed, OUTPUT);
Serial.begin(115200); 

}

void loop() {
//digitalWrite (MotorRightForward, HIGH);
//digitalWrite (MotorLeftForward, HIGH);
//digitalWrite (MotorRightBack, LOW);
//digitalWrite (MotorLeftBack, LOW);
//motorRight.Stop();
//analogWrite (MotorRightSpeed, 0);
//digitalWrite (MotorRightForward, HIGH);
//digitalWrite (MotorRightBack, LOW);
int i;
for (i = 110; i <= 255; i += 5) {
 motorRight.Forward(i);
// analogWrite (MotorRightSpeed, i);
 Serial.print(i);
 Serial.print("\n");
 
 delay (1000);  // put your main code here, to run repeatedly:

}

//analogWrite (MotorRightSpeed, 0);
//digitalWrite (MotorRightForward, LOW);
//digitalWrite (MotorRightBack, HIGH);

for (i = 110; i <= 255; i += 5) {
 motorRight.Backward(i);
// analogWrite (MotorRightSpeed, i);
 Serial.print(i);
 Serial.print("\n");
 delay (1000);  // put your main code here, to run repeatedly:

}

//analogWrite (MotorLeftSpeed, 200);
delay (1000);  // put your main code here, to run repeatedly:

}
