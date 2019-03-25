#include <iostream>
#include <wiringPi.h>

int main(void)
{

wiringPiSetup();

pinMode(0,OUTPUT); 
pinMode(8,INPUT); 

for(;;)
{
int ldrstate = digitalRead(8); 
if(ldrstate == HIGH) 
{
digitalWrite(0,HIGH); 
}
else
{
digitalWrite(0,LOW); 
}
 }
return 0;
 }