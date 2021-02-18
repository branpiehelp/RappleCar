/********************************************//** 
© 2021 branpie.com <branpiehelp@gmail.com>
Rapple Car
************************************************/
#define PIN_MR_V 10 //Motor Left Speed
#define PIN_ML_V 11 //Motor Right Speed
#define PIN_MR_D 12 //Motor Left Direction
#define PIN_ML_D 13 //Motor Right Direction
#define FD 0
#define BD 1
void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_ML_V, OUTPUT);
  pinMode(PIN_MR_V, OUTPUT);
  pinMode(PIN_ML_D, OUTPUT);
  pinMode(PIN_MR_D, OUTPUT);
  //Left Motor Test
  digitalWrite(PIN_ML_D, FD);
  digitalWrite(PIN_ML_V, 100);
  delay(1000);
  digitalWrite(PIN_ML_V, 0); 

  //Right Motor Test
  digitalWrite(PIN_MR_D, FD);
  digitalWrite(PIN_MR_V, 100);
  delay(1000);
  digitalWrite(PIN_MR_V, 0); 
}

void loop() {
  // put your main code here, to run repeatedly:

}
