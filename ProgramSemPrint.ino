#include <VarSpeedServo.h>
#include <EasyUltrasonic.h>

EasyUltrasonic hc;// Create the ultrasonic object
EasyUltrasonic hc1;// Create the ultrasonic object
VarSpeedServo myservo;  // create servo object to control a servo
VarSpeedServo myservo1;  // create servo object to control a servo

unsigned long timer, timer2, timer3, timer4;
bool m1, m2, m3, m4;
long distancia, distancia1;

void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(9);
  hc.attach(7, 8);
  hc1.attach(5, 5, 3, 300);
}

void loop() {
  distancia = hc.getDistanceCM();
  distancia1 = hc1.getDistanceCM();
  if(distancia < 30 && distancia!=0){
    if(millis()-timer > 100){
      timer2 = millis();
      if(m2){
        m1 = !m1;
        m2 = false;
      }
    }
  }else{
    if(millis()-timer2 > 100){
      m2 = true;
      timer = millis();
    }
  }

  if(distancia1 < 30 && distancia1!=0){
    if(millis()-timer3 > 100){
      timer4 = millis();
      if(m4){
        m3 = !m3;
        m4 = false;
      }
    }
  }else{
    if(millis()-timer4 > 100){
      m4 = true;
      timer3 = millis();
    }
  }

  if(m1){
    myservo.write(100);
  }else{
    myservo.slowmove(0,30); 
  }

  
  if(m1 || m3){
    myservo1.write(0);
  }else{
    myservo1.slowmove(100,30); 
  }
  
}
