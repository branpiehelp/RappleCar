/********************************************//** 
(c) 2021 branpie.com <branpiehelp@gmail.com>
Rapple X
************************************************/
#ifndef Melody_h
#define Melody_h
enum NOTE{
  note_C4=0,note_D4,note_E4,note_F4,note_G4,note_A4,note_B4,
  note_C5,note_D5,note_E5,note_F5,note_G5,note_A5,note_B5,
  note_C6,REST
};
enum A_SOUND{
  CEG_C=1,
  CE,
  ABC,
};
class Melody{
private:
	int buzzer_pin;
	static const float foct[REST];
public:
	Melody();
	Melody(int buzzer_pin);
	void init(int buzzer_pin);
	void note(enum NOTE tn, int d);
  void asound(enum A_SOUND val, int tempo);
};
#endif
