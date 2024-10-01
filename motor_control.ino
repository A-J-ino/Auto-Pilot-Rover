#include<NewPing.h>
int distance,t,dist;
int p1=7;
int p2=6;
int p3=5;
int p4=4;
int trig=A1;
int echo=A2;

int readping() 
{
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(40);
digitalWrite(trig,LOW);
t=pulseIn(echo,HIGH);
dist=t*0.034/2;
Serial.print("Distance: ");
Serial.println(dist);
return dist;
}
void fwd(){
  digitalWrite(p1, LOW);
  digitalWrite(p2, HIGH);
  digitalWrite(p3, HIGH );
  digitalWrite(p4, LOW);
}
void bwd(){
  digitalWrite(p2, LOW);
  digitalWrite(p1, HIGH);
  digitalWrite(p4, HIGH );
  digitalWrite(p3, LOW);
}
void left(){
  digitalWrite(p1, LOW);
  digitalWrite(p2, HIGH);
  digitalWrite(p3, LOW );
  digitalWrite(p4, HIGH);
}

void Stop(){
  
  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW );
  digitalWrite(p4, LOW);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(p1,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(p3,OUTPUT);
  pinMode(p4,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
 delay(50);
 
distance= readping();
 if (distance<=10){
  Stop();
    delay(300);
   bwd();
    delay(900);
    Stop();
    delay(300);
    while(distance<=10){
      left();
      delay(300);
      Stop();
      distance=readping();
    }
    fwd();
    }
  else fwd();
}
  
