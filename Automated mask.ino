#include <Servo.h>

const int tp=9;
const int ep=10;
int duration;
int h;
int H;

Servo s1;
Servo s2;

void setup() {
  Serial.begin(9600);
  pinMode(tp,OUTPUT);
  pinMode(ep,INPUT);
}

void loop() {
  digitalWrite(tp,LOW);
  delayMicroseconds(10);
  digitalWrite(tp,HIGH);
  delayMicroseconds(10);
  digitalWrite(tp,LOW);


  duration=pulseIn(ep,HIGH);

  h=duration*0.034*0.5;

  if(h<90){
    
    s1.attach(5);
    s2.attach(6);
    s1.write(90);
    s2.write(0);
    delay(250);
    s1.detach();
    s2.detach();
  }

  else{
    s1.attach(5);
    s2.attach(6);
    s1.write(0);
    s2.write(90);
    delay(250);
    s1.detach();
    s2.detach();
  }

  Serial.println("distance");
  Serial.println(h);

  delay(1000);   
  
}
