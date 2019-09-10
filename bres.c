#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include<stdio.h>
int count=0, ax[20], ay[20];
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor4f(1,0,0,1);
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
    Bresenhams(ax[count-2], ay[count-2], ax[count-1], ay[count-1]);
    
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
void draw(GLint xcoordinate, GLint ycoordinate)
{ 
    glColor4f(0.0,1.0,0.0,1.0);
    glBegin(GL_POINTS);
    glVertex2i(xcoordinate,ycoordinate);
    glEnd();
}
int Bresenhams(int x1, int y1, int x2, int y2)
{    
    char buffer[50];

    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x,y,m;

    dx = x2-x1;
    dy = y2-y1;

    m=dy/dx;

    p=2*dy - dx;
   
   if (p>0)
   {
       
   }
   else{
    
   }
    gcvt(m, 5, buffer);
    drawText(buffer);
    glFlush();
    	
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Bresenhams with slope");
    glutDisplayFunc(Bresenhams);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
