#include <SoftwareSerial.h>


#define TRIG 9
#define ECHO 8


bool startSent = false;
long duration;
long distance;
int distance_previous=1;

SoftwareSerial reader(3,4);

void setup() {
 pinMode(TRIG, OUTPUT);
 pinMode(ECHO, INPUT);
  
  Serial.begin(9600);
  reader.begin(9600);
  while(!Serial){}
}

void loop() {

  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

  duration = pulseIn(ECHO,HIGH);
  distance = duration*0.034/2;


  if((distance!=distance_previous)&&distance < 101)
  {
    Serial.println(distance);
    reader.println(String(distance));
  }
  
  distance_previous = distance;
  delay(100);

  
}



//startSent=false;
