#include <GL/glut.h>
#include <stdio.h>
#define WINHEIGHT 597
#define WINLENGTH 1308
#define GRID 0.1
#define HEIGHTI 0.125
#define WIDTHI 0.4

void display (void)
{
  int i;
  double x = 0;
  double y = 0;
  int quadcount = WINLENGTH / GRID;
  float quadsize = 2.0f / (float) quadcount;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_QUADS);
  for (x = 0; x < quadcount; x++)
    {
      float xpos = -1.0f + x * quadsize;
      for ( y = 0; y < quadcount; y++)
	{
	  float ypos = -1.0f + y * quadsize;
	  
	  glVertex2f(xpos, ypos);
	  glVertex2f(xpos + quadsize, ypos);
	  glVertex2f(xpos, ypos + quadsize);
	  glVertex2f(xpos + quadsize, ypos + quadsize);
	}
    }
  glEnd();
  glFlush();
  /*for(i = 0; i < WINLENGTH; i++)
    {
      glColor3f(1.0, 1.0, 1.0);
      glBegin(GL_LINES);
      glVertex2f(x + i, y);
      glVertex2f(x, y + WINHEIGHT);
      glEnd();
      glFlush();
    }
  for(i = 0; i < WINHEIGHT; i++)
    {
      glColor3f(1.0, 1.0, 1.0);
      glBegin(GL_LINES);
      glVertex2f(x, y + i);
      glVertex2f(x + WINLENGTH, y);
      glEnd();
      glFlush();
      }*/
}

int main (int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode ( GLUT_DOUBLE );

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(WINLENGTH, WINHEIGHT);
  glutCreateWindow ("Grid");

  glClearColor (0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);

  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
