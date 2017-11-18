#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#define WORLDX 50
#define WORLDY 50
//Conways Game of Life using OpenGL
//Functions (library) by Ong M and Graphics by Tyler W

unsigned short world[WORLDX][WORLDY];
int x, y;

void grid(void)
{
  
}

void display(double x, double y)
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
      for(i = 0; i < WORLDY; i++)
	{
	  for(j = 0; j < WORLDX; j++)
	    {
	      if(world[i][j] == 0)
		break;
	      if(world[i][j] == 1)
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
