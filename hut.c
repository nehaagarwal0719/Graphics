 #include <GL/gl.h>
#include <GL/glut.h>   
#include<math.h>

void display() {  
 
    int i;float x,y;
    glClearColor(0.317, 0.737, 0.901, 0.2 );  
    glClear( GL_COLOR_BUFFER_BIT );
    
    //hut base
    glBegin(GL_POLYGON);
    glColor3f( 0.5f, 0.30f, 0.05f ); 
    glVertex2f( -0.9,-0.5);
    glVertex2f( -0.6, -0.5);
    glVertex2f( -0.6, -1);
    glVertex2f(	-0.9, -1);
    glEnd(); 
    glBegin(GL_POLYGON);
    glColor3f( 0.5f, 0.35f, 0.05f); 
    glVertex2f( -0.6,-0.5);
    glVertex2f( 0.2, -0.5);
    glVertex2f( 0.2, -1);
    glVertex2f(	-0.6, -1);
    glEnd(); 
    
    //hut top
    glBegin(GL_TRIANGLES);
    glColor3f( 0.5f, 0.25f, 0.05f ); 
    glVertex2f( -0.9,-0.5);
    glVertex2f( -0.6, -0.5);
    glVertex2f( -0.75, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f( 0.5f, 0.30f, 0.20f ); 
    glVertex2f( -0.6,-0.5);
    glVertex2f( -0.75, 0);
    glVertex2f( 0, 0);
    glVertex2f(	0.2, -0.5);
    glEnd();

    //hut door
    glBegin(GL_POLYGON);
    glColor3f( 0.392f, 0.254f, 0.149f); 
    glVertex2f( -0.3,-1);
    glVertex2f( -0.1, -1);
    glVertex2f( -0.1, -0.75);
    glVertex2f(	-0.3, -0.75);
    glEnd();

    //hut windows
     glBegin(GL_POLYGON);
    glColor3f( 0.392f, 0.254f, 0.149f); 
    glVertex2f( -0.5,-0.60);
    glVertex2f( -0.4, -0.60);
    glVertex2f( -0.4, -0.70);
    glVertex2f(	-0.5, -0.70);
    glEnd();
   
    glBegin(GL_POLYGON);
    glColor3f( 0.392f, 0.254f, 0.149f); 
    glVertex2f( 0,-0.60);
    glVertex2f( 0.1, -0.60);
    glVertex2f( 0.1, -0.70);
    glVertex2f(	0, -0.70);
    glEnd();

//SUN
  glBegin(GL_POLYGON);
  glColor3f( 1, 1, 0 );
     x = -0.7;
     y = 0.7;
    double r = .2;
    for (double theta = 0; theta < 360; theta++)
    {

        glVertex2f(x+  r * cos (theta), y+ r * sin (theta));
    }
    glEnd();

    //Tree branch
    glBegin(GL_POLYGON);
    glColor3f( 0.392f, 0.254f, 0.149f); 
    glVertex2f( 0.5,-1);
    glVertex2f( 0.7, -1);
    glVertex2f( 0.7, 0);
    glVertex2f( 0.6, -0.2);
    glVertex2f( 0.5, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f( 0.341, 0.721, 0.180); 
    glVertex2f( 0.5,0);
    glVertex2f( 0.6, -0.2);
    glVertex2f( 0.7, 0);

    glEnd();


    //leaves
    glBegin(GL_POLYGON);
    glColor3f( 0.341, 0.721, 0.180);
     x = 0.4;
     y = 0.0;
     r = .2;
    for (double theta = 0; theta < 360; theta++)
    {

        glVertex2f(x+  r * cos (theta), y+ r * sin (theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f( 0.341, 0.721, 0.180);
     x = 0.8;
     y = 0.0;
     r = .2;
    for (double theta = 0; theta < 360; theta++)
    {

        glVertex2f(x+  r * cos (theta), y+ r * sin (theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.341, 0.721, 0.180);
     x = 0.3;
     y = 0.2;
     r = .2;
    for (double theta = 0; theta < 360; theta++)
    {

        glVertex2f(x+  r * cos (theta), y+ r * sin (theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.341, 0.721, 0.180);
     x = 0.9;
     y = 0.2;
     r = .2;
    for (double theta = 0; theta < 360; theta++)
    {

        glVertex2f(x+  r * cos (theta), y+ r * sin (theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.341, 0.721, 0.180);
     x = 0.6;
     y = 0.2;
     r = .2;
    for (double theta = 0; theta < 360; theta++)
    {

        glVertex2f(x+  r * cos (theta), y+ r * sin (theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.341, 0.721, 0.180);
     x = 0.4;
     y = 0.5;
     r = .2;
    for (double theta = 0; theta < 360; theta++)
    {

        glVertex2f(x+  r * cos (theta), y+ r * sin (theta));
    }
    glEnd();
      glBegin(GL_POLYGON);
    glColor3f(0.341, 0.721, 0.180);
     x = 0.7;
     y = 0.5;
     r = .2;
    for (double theta = 0; theta < 360; theta++)
    {

        glVertex2f(x+  r * cos (theta), y+ r * sin (theta));
    }
    glEnd();


    glutSwapBuffers();
}


int main( int argc, char** argv ) { 

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);    
    glutInitWindowSize(1000,1000);        
    glutInitWindowPosition(100,100);     
    glutCreateWindow("HUT"); 
    glutDisplayFunc(display);            
    glutMainLoop();                 
    return 0;

}

