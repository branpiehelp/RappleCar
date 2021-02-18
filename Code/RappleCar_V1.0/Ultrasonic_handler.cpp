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
#include "Ultrasonic_handler.h"
Ultrasonic_handler::Ultrasonic_handler(int trig_pin, int echo_pin)
{
  this->trig_pin = trig_pin;
  this->echo_pin = echo_pin;
}
void Ultrasonic_handler::init(void)
{ 
  pinMode(this->trig_pin, OUTPUT);
  pinMode(this->echo_pin, INPUT);  
}
long Ultrasonic_handler::update(void)
{ 
	digitalWrite(this->trig_pin, LOW); 
	delayMicroseconds(2);
	digitalWrite(this->trig_pin, HIGH);
	delayMicroseconds(10);   
	digitalWrite(this->trig_pin, LOW);         
	this->duration = pulseIn(this->echo_pin, HIGH);  
	this->distance=this->duration/59;//340/2/10000 //cm return
  Serial.println(this->distance);
	return this->distance;
}
