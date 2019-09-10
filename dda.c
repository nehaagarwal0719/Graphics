#include <math.h>
#include <time.h>
#include <GL/glut.h>
int count=0, ax[20], ay[20];
char name[]="Neha Ag";
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
    glClear(GL_COLOR_BUFFER_BIT);
}

void mouse(int btn, int state, int x, int y)
{
	glClear(GL_COLOR_BUFFER_BIT);
    y = 480-y;
  	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        ax[count]=x;
        ay[count]=y;
        count++;
    }
    if(count%2==0)
    DDA(ax[count-2], ay[count-2], ax[count-1], ay[count-1]);
    
}
void drawText(char *string)
{
	char *c;
	glRasterPos2f(400.0, 450.0);
	for(c=string; *c!='\0';c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}
void drawText1(char *string)
{
    char *c;
    glRasterPos2f(5.0, 450.0);
    for(c=string; *c!='\0';c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}
void DDA(int x1, int y1, int x2, int y2)
{
    double dx=x2-x1;
    double dy=y2-y1;
    double steps;
    double m=dy/dx;
    char buffer[50];
   
    float xinc, yinc, X=x1, Y=y1;
    if(abs(dx)>abs(dy)){
      	steps=abs(dx);
    }
  	else{
        steps=abs(dy);
    }
    xinc=dx/(float)steps;
    yinc=dy/(float)steps;
    glLineWidth(6);
    glPointSize(4);
    
    glColor4f(1,0,0,1);
    glBegin(GL_POINTS);
    	glVertex2d(X,Y);
    	int k;
    	for(k=0; k<steps;k++)
    	{
    		X+=xinc;
    		Y+=yinc;
    		glVertex2d(X,Y);
    	}
    glEnd();
     gcvt(m, 5, buffer);
    drawText(buffer);
    drawText1(name);
    glFlush();
    	
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("DDA with slope");
    glutDisplayFunc(DDA);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
