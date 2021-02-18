/********************************************//** 
© 2021 branpie.com <branpiehelp@gmail.com>
Rapple Car
************************************************/
#ifndef RappleCar_h
#define RappleCar_h
#include "Motor.h"
class RappleCar{
private:
  Motor ml,mr;
  int ml_d_pin;
  int ml_v_pin;
  int mr_d_pin;
  int mr_v_pin;  
  static const float foct[8];
public:
  RappleCar(int ml_d_pin, int ml_v_pin, 
            int mr_d_pin, int mr_v_pin); 
  void init(void);
  void forwardR(int n);
  void forwardL(int n);
  void stop(void);
  void m_info(char m);
  void melody(int tn, int d);
};

#endif
