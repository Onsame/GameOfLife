#include <GL/glut.h>
#include <stdio.h>

void display(void)
{
  int x, y;
  
  for(x = 0; x < 500; x+=5)
    {
      glColor3f(1.0, 1.0, 1.0);
      glBegin(GL_LINES);
      glVertex2f(x, 0);
      glVertex2f(x, 500);
      glEnd();
      glFlush();
    }
  for(y = 0; y < 500; y+=5)
    {
      glColor3f(1.0, 1.0, 1.0);
      glBegin(GL_LINES);
      glVertex2f(0, y);
      glVertex2f(500, y);
      glEnd();
      glFlush();
    }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Grid");

  glClearColor (0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
