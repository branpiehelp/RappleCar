/********************************************//** 
(c) 2021 branpie.com <branpiehelp@gmail.com>
Rapple Car
************************************************/
#ifndef Melody_h
#define Melody_h
enum MELODY{
  C=0,D,E,F,G,A,B,C2,REST
};
class Melody{
private:
	int buzzer_pin;
	static const float foct[8];
public:
	Melody();
	Melody(int buzzer_pin);
	void init(int buzzer_pin);
	void note(int tn, int d);
};
#endif
