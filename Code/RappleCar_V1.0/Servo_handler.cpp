/********************************************//** 
© 2021 branpie.com <branpiehelp@gmail.com>
Rapple Car
************************************************/
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif
#include "Servo_handler.h"
Servo_handler::Servo_handler(int servo_pin)
{
    this->servo_pin=servo_pin;
    this->servo_angle=1450;
    this->old_servo_angle=1450;
    this->d_angle=0;
    this->servo_angle_change=false; 
};
void Servo_handler::init()
{
   pinMode(this->servo_pin, OUTPUT);
   angle(90); 
}
void Servo_handler::update()
{
	// A pulse each 20ms
	if(this->servo_angle_change==true){
		this->d_angle=this->old_servo_angle-this->servo_angle;
		this->d_angle*=0.18;//Swing speed
    this->old_servo_angle-=this->d_angle;
    Serial.println(this->d_angle);
		if(abs(this->d_angle)<=1){
		  this->servo_angle_change=false;
		  this->old_servo_angle=servo_angle;
		  Serial.println(this->old_servo_angle);
		}
		digitalWrite(this->servo_pin, HIGH);
		delayMicroseconds(this->old_servo_angle);// Duration of the pusle in microseconds
		digitalWrite(this->servo_pin, LOW);
		delayMicroseconds(18550); // 20ms - duration of the pusle
		// Pulses duration: 600 - 0deg; 1450 - 90deg; 2300 - 180deg
	}
}
void Servo_handler::angle(int a)
{
  this->servo_angle=map(a,0,180,600,2300);
  //Serial.println(old_servo_angle);
  //Serial.println(servo_angle);
  this->servo_angle_change=true;  
}
