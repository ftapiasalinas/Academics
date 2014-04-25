#include <GL/glut.h>
GLfloat X = 0.0f;        // Translate screen to x direction (left or right)
GLfloat Y = 0.0f;        // Translate screen to y direction (up or down)
void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glLoadIdentity ();      
   gluLookAt (10.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0, 1.0, 0.0);
   while (1){
          glRotatef(5.0f, 0.0f, 1.0f, 0.0f);  // rotate 45� around x & y axis
        
         glColor3f (1.0, 0.0, 0.0);
         glVertex3f( 0.0f, 1.0f, 0.0f);  // Top Of Triangle (Front)
         glVertex3f(-1.0f,-1.0f, 1.0f);  // Left Of Triangle (Front)
         glVertex3f( 1.0f,-1.0f, 1.0f);  // Right Of Triangle (Front)

         glColor3f (1.0, 1.0, 0.0);
         glVertex3f( 0.0f, 1.0f, 0.0f);  // Top Of Triangle (Right)
         glVertex3f( 1.0f,-1.0f, 1.0f);  // Left Of Triangle (Right)
         glVertex3f( 1.0f,-1.0f,-1.0f);  // Right Of Triangle (Right)

         glColor3f (1.0, 0.0, 1.0);
         glVertex3f( 0.0f, 1.0f, 0.0f);  // Top Of Triangle (Back)
         glVertex3f( 1.0f,-1.0f,-1.0f);  // Left Of Triangle (Back)
         glVertex3f(-1.0f,-1.0f,-1.0f);  // Right Of Triangle (Back)

         glColor3f (1.0, 1.0, 1.0); 
         glVertex3f( 0.0f, 1.0f, 0.0f);  // Top Of Triangle (Left)
         glVertex3f(-1.0f,-1.0f,-1.0f);  // Left Of Triangle (Left)
         glVertex3f(-1.0f,-1.0f, 1.0f);  // Right Of Triangle (Left)
glEnd();       
         sleep(100);
             
         glFlush ();
         glClear (GL_COLOR_BUFFER_BIT);
}
}



 
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
