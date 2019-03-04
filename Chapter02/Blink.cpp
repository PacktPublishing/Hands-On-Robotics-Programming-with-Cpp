include <stdio.h>
#include <wiringPi.h>

int main(void)
{
wiringPiSetup();
pinMode(15,OUTPUT);
 
 for(;;)
 {
 digitalWrite(15,HIGH);
 delay(1000);
digitalWrite(15,LOW);
 delay(1000);
 }
return 0;
 }