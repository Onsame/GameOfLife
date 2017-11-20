#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>


//currently built for NCurses
//for 80x24
#define WORLDY 24
#define WORLDX 80
//living and birth values
#define BIRTH 0x8000
#define LIVING 0x4000 
//array where life will grow in a 80x24 screen 
unsigned short world[WORLDY][WORLDX];
//short gen;

void three_seed()
{
  int i,j;
  for (i = 10; i < 13; i++)
    for( j = 38; j < 41; j++)
      {
	world[i][j] = LIVING;
	move(i,j);
	printw("X");
      }
  
}

void start_world()
{
  int i, j;
  initscr();
  for ( i = 0; i < WORLDY; i++)
    for( j = 0; j < WORLDX; j++)
      world[i][j] = 0;
}

//checks one space around returns the next gen as dead or alive 
void check_around (int y, int x)
{
  //ncell is neighboring cell it will increase with every neighboring cell
  int i, j, ncell = 0;
  for (i = -1; i < 2; i++)
    for(j = -1; j < 2; j++)
      {
	
	if ( i == 0 && j == 0 || (y+i) < 0 || (y+i) > WORLDY-1 || (x+j) < 0 || (x+j) > WORLDX-1)
	  continue;
	//checks the short 0x4000
	if(world[y + i][x + j] & LIVING)
	  ncell++;
      }
  if (ncell == 2 || ncell == 3)
    world[y][x]+=BIRTH;
}

void check_world()
{
  int i,j;
  for ( i = 0; i < WORLDY-1; i++)
    for( j = 0; j < WORLDX-1; j++)
	check_around(i,j);
}

void print_life()
{
  int i,j;
  for ( i = 0; i < WORLDY; i++)
    for( j = 0; j < WORLDX; j++)
      {
	world[i][j] = world[i][j] >> 1;
	if (world[i][j] & LIVING)
	  {
	    move(i,j);
	    printw("X");
	  }
	
      }
  refresh();  
}
      
void exit_world()
{
  endwin();
  //  print_std();
  printf("\nDone\n");
  exit(0);
}

int main (void)
{
  char cc;
  start_world();
  three_seed();
  while(1)
    {
    cc = getch();
    if (cc=='q')
      exit_world();
    else
      {
	clear();
	check_world();
	print_life();
      }
    }
}
