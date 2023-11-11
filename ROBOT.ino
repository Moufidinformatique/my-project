#include <Servo.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

float USDA = 0;
float D = 0;
float D2 = 0;
float V = 0;
float LA = 0;

float RA = 0;

void tourner__C3_A0_droite (){
  RA += 90;
  LA += -90;
  initier();

}

float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}
Servo servo_9;
void tourner__C3_A0_gauche (){
  LA += 90;
  RA += -90;
  initier();

}
void RECULER (){
  D += -1;
  D += -1;
  initier();

}
Servo servo_10;
Servo servo_11;
void initier (){
  servo_10.write(LA);
  servo_11.write(RA);

}
void avancer (){
  LA += 1;
  RA += 1;
  initier();

}

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  servo_9.attach(9);
  servo_10.attach(10);
  servo_11.attach(11);

  D = getDistance(2,3);
  servo_9.write(USDA);
  avancer();
  LA = 0;
  RA = 0;
  initier();
  D2 = getDistance(2,3);
  V = ((D - D2));
  while(1) {
      while(!(V > getDistance(2,3)))
      {
        _loop();
        avancer();

      }
      USDA = 180;
      D = getDistance(2,3);
      for(int count=0;count<2;count++){
          avancer();
      }
      D2 = getDistance(2,3);
      if(D == D2){
          RECULER();
          RECULER();
          RECULER();
          if(0.000000 == random(1, 0 +1)){
              tourner__C3_A0_droite();

          }else{
              tourner__C3_A0_gauche();

          }
          USDA = 0;
          servo_9.write(USDA);

      }else{
          while(!(D == D2))
          {
            _loop();
            D = getDistance(2,3);
            avancer();
            D2 = getDistance(2,3);

          }
          RECULER();
          RECULER();
          RECULER();
          if(0.000000 == random(1, 0 +1)){
              tourner__C3_A0_droite();
              tourner__C3_A0_droite();

          }else{
              tourner__C3_A0_gauche();
              tourner__C3_A0_gauche();

          }
          USDA = 0;
          servo_9.write(USDA);

      }

      _loop();
  }

}

void _loop() {
}

void loop() {
  _loop();
}
