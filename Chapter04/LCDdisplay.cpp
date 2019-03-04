#include <wiringPi.h> 
#include <lcd.h> 

#define RS 22 //Register Select
#define E 26 //Enable

#define D4 24 //Data pin 4
#define D5 25 //Data pin 5
#define D6 27 //Data pin 6
#define D7 28 //Data pin 7

int main()
{

int fd; 
wiringPiSetup(); 
fd= lcdInit (2, 16, 4, RS, E, D4, D5, D6, D7, 0, 0, 0, 0); 
lcdPuts(fd, "LCD OUTPUT"); 

}