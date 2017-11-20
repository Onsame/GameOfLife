#include <GL/glut.h>
#include <stdio.h>

#define HEIGHTI 0.125
#define WIDTHI 0.4
  
void display(void)
{
  double x = 0.0;
  double y = 0.0;
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  for (i = 0; i < 100; i++)
    { 
      glColor3f(1.0, 1.0, 1.0);
      glBegin(GL_POLYGON);
      
      glVertex2f(x + HEIGHTI, y);
      glVertex2f(x + HEIGHTI, y + WIDTHI);
      glVertex2f(x, y + WIDTHI);
      glVertex2f(x, y);
      x = x + HEIGHTI;
      y = y + WIDTHI;
      glEnd();
      glFlush();
    }
  /*for (i = 0; i < 1; i++)
    {
      glColor3f(1.0, 1.0, 1.0);
      glBegin(GL_POLYGON);
      glVertex2f(x, y);
      glVertex2f(x + 0.3, y);
      glVertex2f(x + 0.3, y + 0.3);
      glVertex2f(x, y + 0.3);
      x = x + 0.3;
      y = y + 0.3;
      glEnd();
      glFlush();
      }*/
  //  printf("%f, %f\n", x, y);

}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
  
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(800, 800);
  glutCreateWindow ("Many Squares");

  glClearColor (0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);

  glutDisplayFunc(display);
  glutMainLoop();
  
  return 0;
}
