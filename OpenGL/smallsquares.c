#include <GL/glut.h>
#include <stdio.h>

void display(void)
{
  double x = 6;
  double y = 6;
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  for (i = 0; i < 1; i++)
    {
      glColor3f(1.0, 1.0, 1.0);
      glBegin(GL_POLYGON);
      glVertex2f(x, y);
      glVertex2f(x + 0.1, y);
      glVertex2f(x + 0.1, y + 0.1);
      glVertex2f(x, y + 0.1);
      x = x + 0.1;
      y = y + 0.1;
      glEnd();
      glFlush();
    }
  for (i = 0; i < 1; i++)
    {
      glColor3f(1.0, 1.0, 1.0);
      glBegin(GL_POLYGON);
      glVertex2f(x, y);
      glVertex2f(x + 0.1, y);
      glVertex2f(x + 0.1, y + 0.1);
      glVertex2f(x, y + 0.1);
      x = x + 0.1;
      y = y + 0.1;
      glEnd();
      glFlush();
    }
  printf("%f, %f\n", x, y);

}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
  
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(300, 300);
  glutCreateWindow ("Many Squares");

  glClearColor (0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);

  glutDisplayFunc(display);
  glutMainLoop();
  
  return 0;
}
