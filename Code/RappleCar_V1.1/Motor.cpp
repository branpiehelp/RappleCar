/********************************************//** 
(c) 2021 branpie.com <branpiehelp@gmail.com>
Rapple Car
************************************************/
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif
#include "Motor.h"
void Motor::attach(int dir_p, int val_p)
{
	pinMode(dir_p, OUTPUT);
	pinMode(val_p, OUTPUT);
	this->dir_p=dir_p; 
	this->val_p=val_p;
}  
void Motor::set_dir(int dir)
{
	this->dir=dir;
}
void Motor::set_speed(int val)
{
	this->val=val;
}
int Motor::get_dir()
{
  return this->dir;
}
int Motor::get_speed()
{
  return this->val;
}
void Motor::update(void)
{
	digitalWrite(this->dir_p, this->dir);
	analogWrite(this->val_p, this->val);
}
void Motor::info(void)
{
	Serial.print("DIR Pin:");
	Serial.println(this->dir_p);
	Serial.print("VAL Pin:");
	Serial.println(this->val_p);
	Serial.print("DIR:");
	Serial.println(this->dir);
	Serial.print("SPEED:");
	Serial.println(this->val);        
}
