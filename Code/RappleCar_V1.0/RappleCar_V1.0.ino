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
#define PIN_ML_V 10 //Motor Left Speed
#define PIN_MR_V 11 //Motor Right Speed
#define PIN_ML_D 12 //Motor Left Direction
#define PIN_MR_D 13 //Motor Right Direction

SoftwareSerial mySerial(5, 6); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
RappleCar rapple(PIN_ML_D,PIN_ML_V,PIN_MR_D,PIN_MR_V);
Melody music(PIN_BUZZER);
Servo_handler arm(PIN_SERVO);
Ultrasonic_handler eye(PIN_TRIGER,PIN_ECHO);
void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600); 
  rapple.init();
  music.init();
  arm.init();
  eye.init();
  //music.note(C,300);
  //music.note(E,300);
  //music.note(G,300);
  //music.note(REST,1000);
  //music.note(C2,300);  
}

String myCmd="";
long int counter=0;
void loop() {
  arm.update();
  if(counter%30000==0){ //Time tick about 1sec
    if(eye.update()<10){ //10cm check
      Serial.println("Siren");
      music.note(C2,300);
    }
  }
  while(Serial.available()){
    char tmp;
    tmp=(char)Serial.read();
    myCmd+=tmp;
    mySerial.write(tmp); //시리얼로 블루투스 AT커멘드 입력가능
    delay(5);
  }
  while(mySerial.available()){
    char tmp;
    tmp=(char)mySerial.read();
    myCmd+=tmp;
    Serial.write(tmp); //블루투스 커멘드를 시리얼로 모니터링 가능
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
  counter++;  
}
