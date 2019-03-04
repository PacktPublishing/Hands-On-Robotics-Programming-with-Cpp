//LCD_ULTRASONIC SENSOR CODE

#include <stdio.h>
#include <iostream>
#include <wiringPi.h>
#include <lcd.h> 

using namespace std;

#define trigger 12
#define echo 13
#define RS 22                   //Register Select
#define E 26                    //Enable
#define D4 24                   //Data pin 4
#define D5 25                   //Data pin 5
#define D6 27                   //Data pin 6
#define D7 28                   //Data pin 7

long startTime;
long stopTime;

int main()
{
  wiringPiSetup();

  pinMode(trigger,OUTPUT);
  pinMode(echo, INPUT); 
  
  int fd; 
  wiringPiSetup(); 
  fd= lcdInit (2, 16, 4, RS, E, D4, D5, D6, D7, 0, 0, 0, 0); 
  lcdPuts(fd, "LCD OUTPUT"); 

for(;;)
{
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
 lcdPosition(fd, 0, 0);           //position the cursor on column 0, row 0
 lcdPuts(fd, "Distance: ");      //this code will print Distance text
 lcdPosition(fd, 0, 1);          //position the cursor on column 0, row 1
 lcdPrintf(fd, distance);        // print the distance value
 lcdPuts(fd, " cm");
 delay(2000);
 clear();                     
}
return 0
}

