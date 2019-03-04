#include <ncurses.h>
#include <wiringPi.h>
#include <stdio.h>
int main()
{
 wiringPiSetup();

 pinMode(15,OUTPUT); //LED 1 pin
 pinMode(4, OUTPUT); //LED 2 pin
 pinMode(27,OUTPUT); //Buzzer pin

for(;;){

initscr();

int keypressed = getch();

if(keypressed=='L' || keypressed=='l')
{
 digitalWrite(15,HIGH);
 delay(1000);
 digitalWrite(15,LOW);
 delay(1000);
}

if(keypressed== 69 || keypressed=='e')       // 69 is ASCII number for E.
{
 digitalWrite(4,HIGH);
 delay(1000);
 digitalWrite(4,LOW);
 delay(1000);
}

if(keypressed=='D' || keypressed=='d')
{
 digitalWrite(15,HIGH);
 delay(1000);
 digitalWrite(15,LOW);
 delay(1000);
 digitalWrite(4,HIGH);
 delay(1000);
 digitalWrite(4,LOW);
 delay(1000);
}

if(keypressed=='B' || keypressed== 98)        //98 is ASCII number for b
{
 digitalWrite(27,HIGH);
 delay(1000);
 digitalWrite(27,LOW);
 delay(1000);
 digitalWrite(27,HIGH);
 delay(1000);
 digitalWrite(27,LOW);
 delay(1000);
}

if(keypressed=='x' || keypressed =='X')
{
break; 
}

refresh();
}
endwin(); // 
return 0; 
}