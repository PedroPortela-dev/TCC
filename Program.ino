#include <Servo.h>
#include <HCSR04.h>

HCSR04 hc(5, 6); //initialisation class HCSR04 (trig pin , echo pin)
Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val, val1;    // variable to read the value from the analog pin
unsigned long timer, timer2;
bool m1, m2;
long distancia;

void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  distancia = hc.dist();
//  Serial.println(distancia);
  if(distancia < 10 && distancia!=0){
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

  if(m1){
    myservo.write(180);
   Serial.println("aberto"); 
  }else{
    Serial.println("fechado");
    myservo.write(0); 
  }
}