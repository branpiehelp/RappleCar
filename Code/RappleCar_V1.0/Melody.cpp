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
#include "Melody.h"
Melody::Melody()
{
}
Melody::Melody(int buzzer_pin)
{
	Melody::init(buzzer_pin);
}
void Melody::init(int buzzer_pin)
{
  this->buzzer_pin=buzzer_pin;
	pinMode(this->buzzer_pin, OUTPUT);
}
void Melody::note(int tn, int d)
{
	if(tn!=REST){
	  tone(this->buzzer_pin, foct[tn]);
	  delay(d);
	  noTone(this->buzzer_pin);
	  delay(d/10);
	}
	else{
	  delay(d);
	}
}  
const float Melody::foct[8]=
  {261.6, 293.7, 329.6, 349.2, 392.0, 440.0, 493.9, 
  1046.5};
