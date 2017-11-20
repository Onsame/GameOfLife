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
  for (i = 13; i < 16; i++)
    for( j = 13; j < 16; j++)
      {
	world[i][j] = LIVING;
	move(i,j);
	if (world[i][j] & LIVING)
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

//checks one space around returns dead or alive 
void check_around (int y, int x)
{
  //ncell is neighboring cell it will increase with every neighboring cell
  int i, j, ncell = 0;
  for (i = -1; i < 2; i++)
    for(j = -1; j < 2; j++)
      {
	
	if ( i == 0 && j == 0 )
	  continue;
      //checks the short 16384 = 0100000000000000
      //is if it greater then we have an alive cell
	if(world[y + i][x + j] & LIVING)
	  ncell++;
      // else
      //	continue;
      }
  if (ncell == 2 || ncell == 3)
    world[y][x]=BIRTH;
 
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
  for ( i = 0; i < WORLDY-1; i++)
    for( j = 0; j < WORLDX-1; j++)
      {
	if (world[i][j] & BIRTH)
	  {
	    move(i,j);
	    printw("X");
	    world[i][j] = LIVING;
	  }
	//world[i][i] = world[i][j] >> 1;
      }
  refresh();  
}

/*void print_std()
{
  int i,j;
  for ( i = 0; i < WORLDY; i++)
    for( j = 0; j < WORLDX; j++)
      {
	if (world[i][j] & LIVING || world[i][j] & BIRTH)
	  printf("%u\n",world[i][j]);
      }
}*/
      
void exit_world()
{
  endwin();
  //  print_std();
  printf("\nDone\n");
}

int main (void)
{
  start_world();
  three_seed();
  getch();
  clear();
  check_world();
  print_life();
  getch();
  clear();
  check_world();
  print_life();
  getch();
  exit_world();
}
