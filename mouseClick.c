#include<GL/glut.h> 
#include<stdlib.h> 
#include<stdbool.h>
#include<math.h>
#include<stdio.h>

float x,y;
bool check=true;
float ax[100];
int c=0,i;

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
       check=true;
       
        x = mousex;
        y = 480-mousey;         
        }              
glutPostRedisplay();
     }
          
void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}        

void display(void)
{  
  if(check)  
    {      
    	glBegin(GL_POLYGON); 
      glColor4f(1.0, 0, 0.0, 0.0);
      glVertex2f(x,y);
      glVertex2f(x+20,y);
      glVertex2f(x+20,y-30);
      glVertex2f(x,y-30);
    }  
  glEnd();
  glFlush();
  //unsigned char string[] = "The quick god jumps over the lazy brown fox.";
   //int w;
   //w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
    //for(i=0;i<c;i++){
     
      ax[c]=x;
      ax[c]=y;
      c++;
      for(i=0;i<c;i++){
         printf("%0.6lf\n%0.6lf\n",ax[i],ax[i]);
      }
     //}
}

int main(int argc,char** argv)
{
	  glutInit(&argc,argv);
    glutInitWindowSize(640,480);  
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("mouse click");
    glClearColor(1, 1, 1, 0); 
    glClear(GL_COLOR_BUFFER_BIT); 
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}