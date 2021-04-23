/********************************************//** 
(c) 2021 branpie.com <branpiehelp@gmail.com>
Rapple Car
************************************************/
#include <SoftwareSerial.h>
#include "RappleCar.h"
#include "Melody.h"
#include "Servo_handler.h"
#include "Ultrasonic_handler.h"
#define PIN_BUZZER 4  //BUZZER Pin
#define PIN_BT_TX 5
#define PIN_BT_RX 6
#define PIN_TRIGER 7
#define PIN_ECHO 8
#define PIN_SERVO 9
#define PIN_MR_V 10 //Motor Right Speed
#define PIN_ML_V 11 //Motor Left Speed
#define PIN_MR_D 12 //Motor Right Direction
#define PIN_ML_D 13 //Motor Left Direction

SoftwareSerial bt(PIN_BT_TX, PIN_BT_RX);
RappleCar rapple(PIN_ML_D,PIN_ML_V,PIN_MR_D,PIN_MR_V);
Melody music;
Servo_handler arm;
Ultrasonic_handler eye;
String myCmd="";
unsigned long int counter=0;

//setup()
void setup()
{
  Serial.begin(9600);    //Serial Default Baud Rate
  bt.begin(38400); //Bluetooth 4.0 BLE Default Baud Rate 
  rapple.init();
  music.init(PIN_BUZZER);
  arm.init(PIN_SERVO);
  eye.init(PIN_TRIGER,PIN_ECHO);
  music.asound(CEG_C,1);  
  music.asound(CE,1);  
  music.asound(CE,1); 
  music.asound(ABC,1);  
}
void _loop() {
  arm.update();
}
//loop()
void timer_loop() {
  if(counter%(2000)==0){//2 sec timer
    int tmp=eye.update();
    if(tmp<10 && tmp>0){ //10cm check
      Serial.println("Siren");
      music.note(note_C4,300);
    }
  }
  counter=millis();
}
void cmd_handler() {
  myCmd="";
  while(Serial.available()){
    char tmp;
    tmp=(char)Serial.read();
    myCmd+=tmp;
    bt.write(tmp); //Serial to BT
    delay(5);
  }
  while(bt.available()){
    char tmp;
    tmp=(char)bt.read();
    myCmd+=tmp;
    Serial.write(tmp); //BT to Serial
    delay(5);
  }
  if(!myCmd.equals("")){
      myCmd.replace("\n","");
      myCmd.replace("\r","");    
      int num,num2;
      char sel;
      Serial.println(">>>"+myCmd);
      String cmd=myCmd.substring(0, myCmd.indexOf(" "));
      if(cmd.equals("stop")){
        rapple.stop();
      }
      else if(cmd.equals("forwardR")){
        sscanf(myCmd.c_str(),"forwardR %d",&num);
        rapple.forwardR(num);
      }    
      else if(cmd.equals("forwardL")){
        sscanf(myCmd.c_str(),"forwardL %d",&num);
        rapple.forwardL(num);
      }    
      else if(cmd.equals("forward")){
        sscanf(myCmd.c_str(),"forward %d",&num);
        rapple.forwardL(num);
        rapple.forwardR(num);
      } 
      else if(cmd.equals("backward")){
        sscanf(myCmd.c_str(),"backward %d",&num);
        rapple.backwardL(num);
        rapple.backwardR(num);
      }
      else if(cmd.equals("fa")){//forward Accelator
        sscanf(myCmd.c_str(),"fa %d",&num);
        rapple.fwAccelL(num);
        rapple.fwAccelR(num);
      }            
      else if(cmd.equals("tr")){//turn right
        sscanf(myCmd.c_str(),"tr %d",&num);
        rapple.turnRight(num);
      }     
      else if(cmd.equals("tl")){//turn right
        sscanf(myCmd.c_str(),"tl %d",&num);
        rapple.turnLeft(num);
      }   
      else if(cmd.equals("m_info")){
        sscanf(myCmd.c_str(),"m_info %c",&sel);
        rapple.m_info(sel);
      }   
      else if(cmd.equals("arm")){
        sscanf(myCmd.c_str(),"arm %d",&num);
        arm.angle(num);
      }
  }
}
void loop() {
  _loop();
  timer_loop();
  cmd_handler();
}
