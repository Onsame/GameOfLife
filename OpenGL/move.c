#include <GL/glut.h>
#include "GL/gl.h"
#include "GL/freeglut.h"
#include <stdio.h>

void display(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  
  glColor3f(1.0, 1.0, 1.0);
  glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0);

  glBegin(GL_TRIANGLES);
  int x, y;
  for (x = 0; x < 150.0; x+= 50)
    for (y = 0; y < 150.0; y+= 50)
      {
	glVertex2f(x+100.0, y+100.0);
	glVertex2f(x+-100.0, y+-100.0);
	glVertex2f(x+-50.0, y+-50.0);
      }
  glEnd();
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Test");
  
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
