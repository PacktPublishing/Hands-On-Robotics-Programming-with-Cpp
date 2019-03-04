#include <stdio.h>
#include <iostream>
#include <wiringPi.h>

using namespace std;

#define trigger 12
#define echo 13

long startTime;
long stopTime;

int main()
{

 wiringPiSetup();

 pinMode(trigger,OUTPUT);
 pinMode(echo, INPUT); 

for(;;){
 digitalWrite(trigger,LOW);
 delay(500);

 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);

 digitalWrite(trigger,LOW); 

 while(digitalRead(echo) == LOW);
 startTime = micros();

 while(digitalRead(echo) == HIGH);
 stopTime = micros(); 
 
long totalTime= stopTime - startTime; 
 float distance = (totalTime * 0.034)/2;

 cout << "Distance is: " << distance << " cm"<<endl;
 delay(2000);
}
return 0;
}