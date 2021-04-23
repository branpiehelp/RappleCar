/********************************************//** 
(c) 2021 branpie.com <branpiehelp@gmail.com>
Rapple X
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
void Melody::note(enum NOTE tn, int d)
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
void Melody::asound(enum A_SOUND val, int tempo)
{
  if(val==CEG_C){
    Melody::note(note_C4,300/tempo);
    Melody::note(note_E4,300/tempo);
    Melody::note(note_G4,300/tempo);
    Melody::note(REST,1000/tempo);
    Melody::note(note_C6,600/tempo);
  }  
  else if(val==CE){
    Melody::note(note_C5,500/tempo);
    Melody::note(note_E5,500/tempo);
  } 
  else if(val==ABC){
    Melody::note(note_A4,100/tempo);
    Melody::note(note_B4,100/tempo);
    Melody::note(note_C4,100/tempo);
  } 
}
const float Melody::foct[REST]=
{261.6, 293.7, 329.6, 349.2, 392.0, 440.0, 493.9, 
 523.3,587.3,659.3,698.5,784,880,987,
 1046.5};

//End of file
