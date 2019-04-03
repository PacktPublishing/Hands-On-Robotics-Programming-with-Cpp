#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
int main(void)
{
 wiringPiSetup();
 softPwmCreate (15, 0, 100) ;
 for(;;)
 {
 softPwmWrite (15, 25);
 delay(1000);
 softPwmWrite (15, 0);
 delay(1000);
 softPwmWrite (15, 50);
 delay(1000);
 softPwmWrite (15, 0);
 delay(1000);
 softPwmWrite (15, 100);
 delay(1000);
 softPwmWrite (15, 0);
 delay(1000);
 }
return 0;
 }
