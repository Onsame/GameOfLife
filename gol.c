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
  glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // glLoadIdentity();
  grid();
<<<<<<< HEAD
<<<<<<< HEAD
   while(1)
     {
       check_world();
       birth();
       for(x = 0; x < WORLDX-1; x++)
	 {
	   for(y = 0; y < WORLDY-1; y++)
	     {
	       if(world[x][y] == LIVING)
		 {
		   draw_cell(x, y);
		 }
	       else if(world[x][y] != LIVING && world[x][y] == 0x2000)  
		 {
		   draw_dead_cell(x, y);
		 }
	     }
	 }
       usleep(100000);
       grid();
      //continue;
     }
}

void init_world()
{
  start_world();
  three_seed();
=======
  while (1)
=======
  while(1)
>>>>>>> 0ed642bb56afbb5e072b6929618debaaa5b42d1d
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
<<<<<<< HEAD
>>>>>>> 631a68ddcff21370b245b4041ae40f8c2aafe038
=======
  check_world();
  birth();
>>>>>>> 0ed642bb56afbb5e072b6929618debaaa5b42d1d
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
<<<<<<< HEAD
  glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0);
  init_world();
  glutDisplayFunc(display);
  //  usleep(1000);
=======
  glOrtho(0.0, WORLDX, 0.0, WORLDY, -1.0, 1.0);
  glutDisplayFunc(display);
  usleep(1000);
>>>>>>> 631a68ddcff21370b245b4041ae40f8c2aafe038
  glutMainLoop();

  //return 0;
}
