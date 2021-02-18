/********************************************//** 
© 2021 branpie.com <branpiehelp@gmail.com>
Rapple Car
************************************************/
#ifndef Servo_handler_h
#define Servo_handler_h

class Servo_handler{
private:
	int servo_pin;
	float servo_angle;
	float old_servo_angle;
	float d_angle;
	bool servo_angle_change;
public:
  Servo_handler(int servo_pin);
  void init(void);
	void update(void);
	void angle(int a);
};
#endif
