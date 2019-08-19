 #include <GL/gl.h>
#include <GL/glut.h>   
#include<math.h>

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);

}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        circles(x,y);
    }
}
void circles(int x, int y){

    glBegin(GL_POLYGON);
    glColor3f( 1, 0, 0 );
       double r = .2;
       for (double theta = 0; theta < 360; theta++)
        {
            glVertex2f(x+  r * cos (theta), y+ r * sin (theta));
         }
       glEnd();
       glFlush();
}

  



int main( int argc, char** argv ) { 

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);    
    glutInitWindowSize(1000,1000);        
    glutInitWindowPosition(100,100);     
    glutCreateWindow("On click trying"); 
    init();
    glutDisplayFunc(circles);
    glutMouseFunc(mouse);            
    glutMainLoop();                 
    return 0;

}

