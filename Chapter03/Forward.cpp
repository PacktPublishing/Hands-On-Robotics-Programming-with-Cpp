#include <stdio.h>
#include <wiringPi.h>

int main(void)
{
wiringPiSetup();
pinMode(0,OUTPUT); 
pinMode(2,OUTPUT); 
pinMode(3,OUTPUT);
pinMode(4,OUTPUT); 
 
 
 for(int i=0; i<1;i++)
 {
digitalWrite(0,HIGH); //PIN O & 2 will move the Left Motor
digitalWrite(2,LOW);
digitalWrite(3,HIGH); //PIN 3 & 4 will move the Right Motor
digitalWrite(4,LOW);
delay(3000);
 }
return 0;
 }