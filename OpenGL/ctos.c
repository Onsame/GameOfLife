#include <GL/glut.h>
#include <stdio.h>

void display(void)
{
  float x, y;
  printf("Enter the x coordinate where you want the square to be displayed\n");
  scanf("%f", &x);
  printf("Enter the y coordinate where you want the square to be displayed\n");
  scanf(" %f", &y);

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(x, y);
  glVertex2f(x + 0.1, y);
  glVertex2f(x + 0.1, y + 0.1);
  glVertex2f(x, y + 0.1);
  glEnd();
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
  
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(300, 300);
  glutCreateWindow ("Input Squares");
  
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);

  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
