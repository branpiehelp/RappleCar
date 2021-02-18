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
#include "RappleCar.h"
RappleCar::RappleCar(int ml_d_pin, int ml_v_pin, 
            int mr_d_pin, int mr_v_pin)
{
  this->ml_d_pin=ml_d_pin;
  this->ml_v_pin=ml_v_pin;
  this->mr_d_pin=mr_d_pin;
  this->mr_v_pin=mr_v_pin;
}
void RappleCar::init()
{
  this->ml.attach(this->ml_d_pin,this->ml_v_pin);
  this->mr.attach(this->mr_d_pin,this->mr_v_pin);
}
void RappleCar::forwardR(int n)
{
	//Serial.println("forwardR");
	this->mr.set_dir(FD);
	this->mr.set_speed(n);
	this->mr.update();
}
void RappleCar::forwardL(int n)
{
	//Serial.println("forwardL");
	this->ml.set_dir(FD);
	this->ml.set_speed(n);
	this->ml.update();
}
void RappleCar::stop(void)
{
	forwardR(0);
	forwardL(0);
}
void RappleCar::m_info(char m)
{
	if(m=='l'){
	  this->ml.info();
	}
	else if(m=='r'){
	  this->mr.info();
	}
}
