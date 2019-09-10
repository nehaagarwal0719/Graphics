#include<GL/glut.h> 
#include<stdlib.h> 
#include<stdbool.h>
#include<math.h>
#include<stdio.h>

float x_pos,y;
bool check;
float ax[100],ax[100];
int c=0,i;

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
       check=true;
        x_pos = mousex;
        y = 480-mousey;
        ax[c]=x_pos;
        ax[c]=y;
        c++;
    } 
glutPostRedisplay();
}          

void display(void)
{  

    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
if(check)  
{	
  glBegin(GL_POLYGON); 
  glColor4f(1, 0.0, 0.0, 0.0);
  glVertex2f(x_pos,y);
  glVertex2f(x_pos+20,y);
  glVertex2f(x_pos+20,y-30);
  glVertex2f(x_pos,y-30);
}
  glEnd();
  glutSwapBuffers(); 
   for(i=0;i<c;i++){
         printf("%0.6lf\n%0.6lf\n",ax[i],ax[i]);
      }
       printf("---\n");
   char buf[100] = {0};
  sprintf(buf, "Daksh Pratap Singh");
  renderbitmap(0, 0, GLUT_BITMAP_TIMES_ROMAN_24, buf);    
}

void renderbitmap(float x, float y, void *font, char *string) {
  char *c;

  glRasterPos2f(x, y);
  for(c = string; *c != '\0'; c++)
    glutBitmapCharacter(font, *c);
}

void timer(int x)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);
	if(y<480)
	{
	y +=0.5;
	
	}  
}

void keyboardCB( unsigned char key, int x, int y )
{
  switch ( key )
  {
    case 27: // Escape key
      glutDestroyWindow (1);
      exit (0);
      break;
  }
  if(key == 32)
	{
	timer(x_pos);
	glutPostRedisplay();
	}
  
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
    glutInitWindowSize(640,480);  
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("mouse click");
    glClearColor(1, 1, 1, 0); 
    glClear(GL_COLOR_BUFFER_BIT); 
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboardCB);
    glutMainLoop();
    return 0;
}
