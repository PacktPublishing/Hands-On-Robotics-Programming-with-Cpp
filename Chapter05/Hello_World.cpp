#include <ncurses.h>
#include <stdio.h>

int main()
{
initscr();                         //initializes and clear the screen
int keypressed = getch()                    
if(keypressed == 'h' || keypressed == 'H')
{
printw("Hello World");             //will print Hello World message
}
getch();
refresh(); 

endwin();                          // frees up memory and ends ncurses
return 0;
}