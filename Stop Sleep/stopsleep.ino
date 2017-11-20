#include <elapsedMillis.h>

elapsedMillis timeElapsed;

#define trigger 500
#define IR A0
#define GREEN 12
#define YELLOW 11
#define RED 10
#define BUZZ A3
unsigned int interval = 800;
unsigned int interval2 = 500;
int sensor=0;
int k;
void setup() {
  // put your setup code here, to run once:
pinMode(IR,INPUT);
pinMode(GREEN,OUTPUT);
pinMode(YELLOW,OUTPUT);
pinMode(RED,OUTPUT);
pinMode(BUZZ,OUTPUT);

for(k=0;k<3;k++)
{
digitalWrite(GREEN,HIGH);
delay(100);
digitalWrite(GREEN,LOW);
digitalWrite(YELLOW,HIGH);
delay(100);
digitalWrite(RED,HIGH);
delay(100);

digitalWrite(RED,LOW);
digitalWrite(GREEN,LOW);
digitalWrite(YELLOW,LOW);
digitalWrite(RED,LOW);
delay(50);
}
for(k=0;k<5;k++)
{
  digitalWrite(BUZZ,HIGH);
  delay(50);
  digitalWrite(BUZZ,LOW);
  delay(50);
}
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
 delay(70);
  sensor=analogRead(IR);
 if(sensor< trigger)
{
  digitalWrite(GREEN,HIGH);
  digitalWrite(YELLOW,LOW);
digitalWrite(RED,LOW);
 digitalWrite(BUZZ,LOW);

  timeElapsed=0;
}

 if(sensor>trigger&& timeElapsed>=interval2)
{
  digitalWrite(GREEN,LOW);
  digitalWrite(YELLOW,HIGH);
digitalWrite(RED,LOW);
 digitalWrite(BUZZ,LOW);
}
 if(sensor>trigger&& timeElapsed>=interval)


{ 
    timeElapsed=0;
  while(timeElapsed<2000)
{
  digitalWrite(GREEN,LOW);
  digitalWrite(YELLOW,LOW);
digitalWrite(RED,HIGH);
 digitalWrite(BUZZ,HIGH);
}
} 

Serial.print(sensor);
Serial.print("  ");
Serial.println(timeElapsed);
}
