#include <GL/glut.h>


void init(void) 
{
  
 glClearColor (0.0, 0.0, 0.0, 0.0);
   
glShadeModel (GL_FLAT);
  // GLfloat light_ambient[] = { 1.0, 0.0, 0.0, 1.0 }; //blue
//   GLfloat light_diffuse[] = { 1.0, 0.0, 0.0,1.0 }; //red
//   GLfloat light_specular[] = { 1.0, 1.0, 0.0,1.0}; //green
//   GLfloat light_position[] = { 10.0, 0.0, 0.0, 1.0 }; 
//
//   glLightfv (GL_LIGHT0, GL_AMBIENT, light_ambient); 
//   glLightfv (GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
//   glLightfv (GL_LIGHT0, GL_SPECULAR, light_specular); 
//   glLightfv (GL_LIGHT0, GL_POSITION, light_position); 
//
//    glEnable (GL_LIGHTING); 
//    glEnable (GL_LIGHT0); 
//    glDepthFunc(GL_LESS); 
//    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glLoadIdentity ();      
   gluLookAt (0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   //gluLookAt (0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0, 1.0, 0.0);
   //gluLookAt (10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 1.0, 0.0);
   glBegin(GL_TRIANGLES);
       //  glColor3f (1,1,1);
//         glNormal3f (0, 0, 0);
//         glVertex3f( 0, 1, 0);  
//         glNormal3f (0,0,0);
//         glVertex3f(-1, 0, 0 );  
//         glNormal3f (0,0, 1);
//         glVertex3f( 1, 0, 0);  
      glBegin(GL_QUADS);
	// front
	//glNormal3f(0, 0, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, 1, 1);

	// back
	//glNormal3f(0, 0, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glVertex3f(1, 1, -1);
	glVertex3f(1, -1, -1);
	glVertex3f(-1, -1, -1);

	// top
	//glNormal3f(0, 1, 0);
	glColor3f(0, 0, 1);
	glVertex3f(-1, 1, -1);
	glVertex3f(-1, 1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, -1);

	// bottom
	//glNormal3f(0, -1, 0);
	glColor3f(1, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);
	glVertex3f(-1, -1, 1);

	// left
	//glNormal3f(-1, 0, 0);
	glColor3f(0, 1, 1);
	glVertex3f(-1, 1, -1);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);
	glVertex3f(-1, 1, 1);

	// right
	//glNormal3f(1, 0, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(1, 1, -1);
	glEnd();   
          
   glEnd();       
   glFlush ();
   glClear (GL_COLOR_BUFFER_BIT);
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
