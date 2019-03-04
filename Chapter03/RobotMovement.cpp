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
	 
/* FORWARD */
digitalWrite(0,HIGH); //PIN O & 1 will move the Left Motor Forward
digitalWrite(1,LOW);
digitalWrite(2,HIGH); //PIN 2 & 3 will move the Right Motor Forward
digitalWrite(3,LOW);
delay(3000);

/* BACKWARD */
digitalWrite(0,LOW); //PIN O & 1 will move the Left Motor Backward
digitalWrite(1,HIGH);
digitalWrite(2,LOW); //PIN 2 & 3 will move the Right Motor Backward
digitalWrite(3,HIGH);
delay(3000);

/* STOP */
digitalWrite(0,HIGH); //PIN O & 1 will stop the Left Motor
digitalWrite(1,HIGH);
digitalWrite(2,HIGH); //PIN 2 & 3 will stop the Right Motor
digitalWrite(3,HIGH);
delay(3000);

/* AXIAL LEFT TURN */
digitalWrite(0,LOW);
digitalWrite(1,HIGH);
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
delay(500);

/* AXIAL RIGHT TURN */
digitalWrite(0,HIGH);
digitalWrite(1,LOW);
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
delay(500);


/* RADIAL LEFT TURN */
digitalWrite(0,HIGH);
digitalWrite(1,HIGH);
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
delay(1000);


/* RADIAL RIGHT TURN */
digitalWrite(0,HIGH);
digitalWrite(1,LOW);
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
delay(1000);



 }
return 0;
 }