#include <stdio.h>
#include <wiringPi.h>

int main(void)
{
wiringPiSetup();
pinMode(0,OUTPUT); 
pinMode(1,OUTPUT); 
pinMode(2,OUTPUT);
pinMode(3,OUTPUT); 
 
 
 for(int i=0; i<1;i++)
 {
digitalWrite(0,HIGH); //PIN O & 1 will move the Left Motor
digitalWrite(1,LOW);
digitalWrite(2,HIGH); //PIN 2 & 3 will move the Right Motor
digitalWrite(3,LOW);
delay(3000);
 }
return 0;
 }