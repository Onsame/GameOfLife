#include <GL/glut.h>
#include <life.c>
#include <stdio.h>
#include <stdlib.h>
#include "life.c"
#define GWORLDX 50
#define GWORLDY 50
//Conways Game of Life using OpenGL
//Functions (library) by Ong M and Graphics by Tyler W

unsigned short gworld[GWORLDX][GWORLDY];
int x, y;

void grid(void)
{
  
}

void display(void)
{
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(x + 1, y + 1);
  glVertex2f(x + 1, y - 1);
  glVertex2f(x - 1, y + 1);
  glVertex2f(x - 1, y - 1);
  glEnd();
  glFlush();
}

int main(int argc, char **argv)
{
  int i, j;
  start_world();
  three_seed();
  glutInit(&argc, argv);
  glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(500, 500);
  glutCreateWindow ("Game Of Life");

  glClearColor (0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0);

  while(1)
    {
      check_world();
      birth();
      for(i = 0; i < GWORLDY; i++)
	{
	  for(j = 0; j < GWORLDX; j++)
	    {
	      if(gworld[i][j] == 0)
		break;
	      if(gworld[i][j] == 1)
		{
		  x = i;
		  y = j;
		  glutDisplayFunc(display);
		  glutMainLoop();
		}
	    }
	}      
    }
}
