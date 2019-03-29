#include <ncurses.h>
#include <stdio.h>
#include <wiringPi.h>


void forward()
{
digitalWrite(0,HIGH);
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
}

void rightturn()
{
digitalWrite(0,HIGH); 
digitalWrite(2,LOW); 
digitalWrite(3,LOW); 
digitalWrite(4,HIGH);
}

void stop()
{
digitalWrite(0,HIGH); 
digitalWrite(2,HIGH); 
digitalWrite(3,HIGH); 
digitalWrite(4,HIGH);
}


int main()
{
wiringPiSetup();
pinMode(0, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
for(;;)
{
initscr();   
keypad(stdscr,TRUE);
refresh(); 
int keypressed = getch();  
 if(keypressed==KEY_UP || keypressed == 'W' || keypressed == 'w')
{
digitalWrite(0,HIGH);
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
}
if(keypressed==KEY_DOWN || keypressed == 'X' || keypressed == 'x')
{
digitalWrite(0,LOW);
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
}
if(keypressed==KEY_LEFT || keypressed == 'A' || keypressed == 'a')
{
digitalWrite(0,LOW);
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);
}
if(keypressed==KEY_RIGHT || keypressed == 'D' || keypressed == 'd')
{
digitalWrite(0,HIGH);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);
}
if(keypressed=='s' || keypressed=='S')
{
digitalWrite(0,HIGH);
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
}
if(keypressed == 'r' || keypressed == 'R')
{
forward();                             //first forward movement
delay(2000);
rightturn();                             //first left turn
delay(500);                            //delay needs to be such that the robot takes a perfect 90 degree right turn

forward();                            //second forward movement
delay(2000);
rightturn();                           //second right turn
delay(500);

forward();                          //third forward movement
delay(2000);
rightturn();                          //third and last left turn
delay(500);

forward();                        //fourth and last forward movement
delay(2000);
stop();                              //stop condition
}
if(keypressed=='e' || keypressed=='E')
{
break;	
}
}
endwin(); 
return 0;	
}
