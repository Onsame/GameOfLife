#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "life.c"
//Conways Game of Life using OpenGL
//Functions (library) by Ong M and Graphics by Tyler W

void grid(void)
{
  int gx, gy;
  
  for(gx = 0; gx < WORLDX; gx += 5)
    {
      glColor3f(1.0, 1.0, 1.0);
      glBegin(GL_LINES);
      glVertex2f(gx, 0);
      glVertex2f(gx, WORLDX);
      glEnd();
      glFlush();
    }
  for(gy = 0; gy < WORLDY; gy += 5)
    {
      glColor3f(1.0, 1.0, 1.0);
      glBegin(GL_LINES);
      glVertex2f(0, gy);
      glVertex2f(WORLDY, gy);
      glEnd();
      glFlush();
    }
}

void draw_cell(int x, int y)
{
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(x*5, y*5);
  glVertex2f(x*5, (y*5)+4.8);
  glVertex2f((x*5)+4.8, y*5);
  glVertex2f((x*5)+4.8, (y*5)+4.8);
  glEnd();
  glFlush();
}

void draw_dead_cell(int x, int y)
{
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2f((x*5), (y*5));
  glVertex2f((x*5), (y*5)+4.8);
  glVertex2f((x*5)+4.8, (y*5));
  glVertex2f((x*5)+4.8, (y*5)+4.8);
  glEnd();
  glFlush();
}

void display(void)
{
  int x, y;
  start_world();
  three_seed();
  glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  grid();
  while(1)
    {
      for(x = 0; x < WORLDX; x++)
	{
	  for(y = 0; y < WORLDY; y++)
	    {
	      if(world[x][y] == LIVING)
		{
		  draw_cell(x, y);
		}
	      else  
		{
		  draw_dead_cell(x, y);
		}
	    }
	}
    }
  check_world();
  birth();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(WORLDX, WORLDY);
  glutCreateWindow("Game Of Life");

  glClearColor (0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, WORLDX, 0.0, WORLDY, -1.0, 1.0);
  glutDisplayFunc(display);
  usleep(1000);
  glutMainLoop();

  return 0;
}
