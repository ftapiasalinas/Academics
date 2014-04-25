#include <GL/glut.h>

void init(void)
{
    GLfloat light_ambient[] = { 0.0, 0.0, 1.0, 1.0 }; 
    GLfloat light_diffuse[] = { 0.0, 0.0, 1.0,1.0 }; 
    GLfloat light_specular[] = { 1.0, 1.0, 1.0,1.0}; 
    GLfloat light_position[] = { 10.0, 7.0, 10.0, 1.0 }; 

   //glLightfv (GL_LIGHT0, GL_AMBIENT, light_ambient); 
   glLightfv (GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
   //glLightfv (GL_LIGHT0, GL_SPECULAR, light_specular); 
   //glLightfv (GL_LIGHT0, GL_POSITION, light_position); 

    glEnable (GL_LIGHTING); 
    glEnable (GL_LIGHT0); 
    glDepthFunc(GL_LESS); 
    glEnable(GL_DEPTH_TEST);

}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   glLoadIdentity ();             /* clear the matrix */
   /* viewing transformation  */
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   glScalef (1.0, 1.0, 1.0);      /* modeling transformation */
   glutSolidSphere (0.6, 56, 26);
   glFlush ();
}

void reshape (int w, int h)
{
     glViewport (0, 0, (GLsizei) w, (GLsizei) h);
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity ();
     glOrtho (-2.5, 2.5, -2.5, 2.5, -5, 5);
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
