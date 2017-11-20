#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>


//currently built for NCurses
//for 80x24
#define WORLDY 80
#define WORLDX 24
//living and birth values 
#define BIRTH -32768
#define LIVING 16384 
//array where life will grow in a 80x24 screen 
short world[WORLDY,WORLDX];
//short gen;

void three_seed()
{
  int i;
  for (i = 0; i < 3; i++)
    for( j = 0; j < 3; j++)
      world[i,j] = 'X';
}
void start_world()
{
  int i, j;
  initscr();
  for ( i = 0; i < WORLDY; i++)
    for( j = 0; j < WORLDX; j++)
      world[i,j] = 0;
}

void exit_scr()
{
  endwin();
}

//checks one space around returns dead or alive 
void check_around (int y, int x)
{
  //ncell is neighboring cell it will increase with every neighboring cell
  int i, j, ncell = 0;
  for (i = 0; i < 3; i++)
    for( j = 0; j < 3; j++)
      {
      //checks the short 16384 = 0100000000000000
      //is if it greater then we have an alive cell
      if(world[ y + i, x + j]>=LIVING)
	ncell++;
      else
	continue;
      }
  if (ncell > 1 || ncell < 4)
    world[ y , x ]+=BIRTH;
 
}

void check_world()
{
  
}
