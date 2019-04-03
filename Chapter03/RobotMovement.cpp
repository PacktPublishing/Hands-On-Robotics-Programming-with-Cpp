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
	 
/* FORWARD  */
digitalWrite(0,HIGH); //PIN O & 2 will move the Left Motor Forward
digitalWrite(2,LOW);
digitalWrite(3,HIGH); //PIN 3 & 4 will move the Right Motor Forward
digitalWrite(4,LOW);
delay(3000);

/* BACKWARD  */
digitalWrite(0,LOW); 
digitalWrite(2,HIGH);
digitalWrite(3,LOW); 
digitalWrite(4,HIGH);
delay(3000);

/* STOP */
digitalWrite(0,HIGH); 
digitalWrite(2,HIGH);
digitalWrite(3,HIGH); 
digitalWrite(4,HIGH);
delay(3000);

/* AXIAL LEFT TURN */
digitalWrite(0,LOW);
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
delay(500);

/* AXIAL RIGHT TURN */
digitalWrite(0,HIGH);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
delay(500);


/* RADIAL LEFT TURN */
digitalWrite(0,HIGH);
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
delay(1000);


/* RADIAL RIGHT TURN */
digitalWrite(0,HIGH);
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
delay(1000);

/* STOP */
digitalWrite(0,HIGH);
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
delay(1000);
 }
return 0;
 }
