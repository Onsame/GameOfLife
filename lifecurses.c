#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>


//currently built for NCurses
//for 80x24
#define WORLDY 80
#define WORLDX 24


//array where life will grow in a 80x24 screen 
char world[WORLDY,WORLDX];

void start_world()
{
  int i, j;
  initscr();
  for ( i = 0; i < WORLDY; i++)
    for( j = 0; j < WORLDX; j++)
      world[i,j] = ' ';
}

void exit_scr()
{
  endwin();
}

void check_nc (int y,int x)
{
  int i, j;
  move( y , x );
}