#include<Servo.h>
Servo servomotor;
int var;
int var1;
int varA0;
int varA1;
int varA2;

unsigned long msegi=0;

void setup()
{
  Serial.begin(9600);
  pinMode (A0,INPUT);
  pinMode (A1,INPUT);
  pinMode (A2,INPUT);
  pinMode (3,OUTPUT);
  servomotor.attach(9);
  servomotor.write(0);
}

void loop ()
{
  varA0=analogRead(A0);
  varA1=analogRead(A1);
  varA2=analogRead(A2);
  unsigned long msegf=millis();
  if(msegf-msegi>=100)
  {
    msegi=msegf;
    Serial.print(varA0);
    Serial.print(",");
    Serial.print(varA1);
    Serial.print(",");
    Serial.println(varA2);
  }
  delay(10);
} 

void serialEvent()
{
  if(Serial.available())
  {
    var=Serial.parseInt();
    var1=Serial.parseInt();
    if(Serial.read()==char(13))
    {
      servomotor.write(var);
      analogWrite (3,var1);
    }
  }
}