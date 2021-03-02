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

SoftwareSerial mySerial(PIN_BT_TX, PIN_BT_RX);
RappleCar rapple(PIN_ML_D,PIN_ML_V,PIN_MR_D,PIN_MR_V);
Melody music;
Servo_handler arm;
Ultrasonic_handler eye;
void setup()
{
  Serial.begin(9600);    //Serial Default Baud Rate
  mySerial.begin(38400); //Bluetooth 4.0 BLE Default Baud Rate 
  rapple.init();
  music.init(PIN_BUZZER);
  arm.init(PIN_SERVO);
  eye.init(PIN_TRIGER,PIN_ECHO);
  music.note(C,300);
  music.note(E,300);
  music.note(G,300);
  music.note(REST,1000);
  music.note(C2,300);  
}

String myCmd="";
long int counter=0;
void loop() {
  arm.update();
  if(counter++%30000==0){ //Time tick about 1sec
    int tmp=eye.update();
    if(tmp<10 && tmp>0){ //10cm check
      Serial.println("Siren");
      music.note(C2,300);
    }
  }
  while(Serial.available()){
    char tmp;
    tmp=(char)Serial.read();
    myCmd+=tmp;
    mySerial.write(tmp); //Serial to BT
    delay(5);
  }
  while(mySerial.available()){
    char tmp;
    tmp=(char)mySerial.read();
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
        rapple.fwAccel(num);
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
  myCmd="";
}
