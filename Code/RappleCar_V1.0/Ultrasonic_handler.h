#ifndef Ultrasonic_handler_h
#define Ultrasonic_handler_h

class Ultrasonic_handler{
private:
	int trig_pin;
	int echo_pin;
	long duration;
	long distance;
public:
  Ultrasonic_handler(int trig_pin, int echo_pin);
  void init(void);
	long update(void);
};
#endif
