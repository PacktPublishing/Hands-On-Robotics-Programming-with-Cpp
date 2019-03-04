
#include <stdio.h>
#include <iostream>
#include <wiringPi.h>
#define echo 3
#define trigger 2

// Definining device parameters
#define I2C_DEVICE_ADDRESS   0x27 // I2C device address
#define firstrow  0x80 // 1st line
#define secondrow  0xC0 // 2nd line

// Define some device constants
#define LCD_CHR  1 // Mode - Sending data
#define LCD_CMD  0 // Mode - Sending command

// LCD_BACKLIGHT = 0x00  # Off

#define ENABLE  0b00000100 // Enable bit

void init_lcd(void);
void lcd_byte(int bits, int mode);
void lcd_toggle_enable(int bits);
void printmessage(const char *s);
void moveCursor(int line); 
void clear(void); 
void typeChar(char val);
void printInt(int i);
void printFloat(float myFloat);
int lcdaddr; 


long startTime;
long stopTime;

using namespace std;

int main()
{
	wiringPiSetup();
	
	pinMode(trigger,OUTPUT);
	pinMode(echo, INPUT);
	pinMode(13,OUTPUT);
	pinMode(14,OUTPUT);
	pinMode(6,OUTPUT);
	pinMode(10,OUTPUT);
	
  lcdaddr = wiringPiI2CSetup(I2C_DEVICE_ADDRESS);
  init_lcd(); // setup LCD
  
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
 
		
	long traveltime = stopTime - startTime;
		
	float distance = (totalTime * 0.034)/2;
	
		
	cout << "Distance is: " << distance << " cm"<<endl;
	if(distance < 7)
   {
   digitalWrite(13,LOW);
   digitalWrite(14,HIGH);
   digitalWrite(6,HIGH);
   digitalWrite(10,LOW);
   delay(500);
   moveCursor(firstrow);
   printmessage("Obstacle Status");
   moveCursor(secondrow);
   printmessage("Obstacle detected");
   clear();
   }
   else
   {
   digitalWrite(13,HIGH);
   digitalWrite(14,LOW);
   digitalWrite(6,HIGH);
   digitalWrite(10,LOW);
   moveCursor(firstrow);
   printmessage("Obstacle Status");
   moveCursor(secondrow);
   printmessage("No Obstacle");
   clear();
}
}
return 0;

}



void printFloat(float myFloat)   {
  char buffer[20];
  sprintf(buffer, "%4.2f",  myFloat);
  printmessage(buffer);
}


void printInt(int i)   {
  char array1[20];
  sprintf(array1, "%d",  i);
  printmessage(array1);
}

// clr lcd go home loc 0x80
void clear(void)   {
  lcd_byte(0x01, LCD_CMD);
  lcd_byte(0x02, LCD_CMD);
}


void moveCursor(int line)   {
  lcd_byte(line, LCD_CMD);
}


void typeChar(char val)   {

  lcd_byte(val, LCD_CHR);
}



void printmessage(const char *s)   {

  while ( *s ) lcd_byte(*(s++), LCD_CHR);

}

void lcd_byte(int bits, int mode)   {


  int bits_high;
  int bits_low;

  bits_high = mode | (bits & 0xF0) | LCD_BACKLIGHT ;
  bits_low = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT ;


  wiringPiI2CReadReg8(lcdaddr, bits_high);
  lcd_toggle_enable(bits_high);


  wiringPiI2CReadReg8(lcdaddr, bits_low);
  lcd_toggle_enable(bits_low);
}

void lcd_toggle_enable(int bits)   {

  delayMicroseconds(500);
  wiringPiI2CReadReg8(lcdaddr, (bits | ENABLE));
  delayMicroseconds(500);
  wiringPiI2CReadReg8(lcdaddr, (bits & ~ENABLE));
  delayMicroseconds(500);
}


void init_lcd()   {

  lcd_byte(0x33, LCD_CMD); 
  lcd_byte(0x32, LCD_CMD); 
  lcd_byte(0x06, LCD_CMD); 
  lcd_byte(0x0C, LCD_CMD); 
  lcd_byte(0x28, LCD_CMD); 
  lcd_byte(0x01, LCD_CMD); 
  delayMicroseconds(500);
}


