/********************************************//** 
(c) 2021 branpie.com <branpiehelp@gmail.com>
Rapple Car
************************************************/
#ifndef Ultrasonic_handler_h
#define Ultrasonic_handler_h

class Ultrasonic_handler{
private:
	int trig_pin;
	int echo_pin;
	long duration;
	long distance;
public:
  Ultrasonic_handler();
  Ultrasonic_handler(int trig_pin, int echo_pin);
  void init(int trig_pin, int echo_pin);
  long update(void);
};
#endif
