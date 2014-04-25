/*This program to draw points, Lines and polygons*/
#include <GL/gl.h>
#include <GL/glut.h>
void myinit(void)
{
  glClearColor(0.8, 0.8, 0.8, 0.0); /* gray background */
 
  glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  glLoadIdentity();                 /* position the "clipping rectangle" */
  gluOrtho2D( 0, 750, 0, 750);/* at -B/2, its right edge at +B/2, its bottom */
  glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}



void display( void )
{
  glClear(GL_COLOR_BUFFER_BIT);     /*clear the window */
 
  glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
  glLoadIdentity();                 /* in terms of World coordinates */

 int X = 9, Y = 0;
GLubyte bitShape1[6] = {0x84 ,0x48,0x48,0x78 ,0x48, 0x30 };
 //GLubyte bitShape1[6] = {0xfe ,0xfe,0xc0,0xc0 ,0xc0, 0xc0 };
 glPixelStorei (GL_UNPACK_ALIGNMENT,1); 
 glRasterPos2i(50,50);
 glColor3f(1.0, 0.0, 0.0);
 glBitmap (7,6, 0.0, 0.0, X, Y, bitShape1); 
                   
 glFlush();                       /* send all commands */
}


int main(int argc, char** argv)
{
  glutInit(&argc,argv);                                   /*initialize the toolkit   */
  glutInitWindowSize( 300, 150 );                         /* Set window size */
  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);           /* Set the display mode */
  glutInitWindowPosition( 100, 100 );  
  glutCreateWindow("My Points");                          /* create window with title */
  
  glutDisplayFunc(display);                               /*tell OpenGL main loop what     */
  myinit();                                               /* set attributes                 */

  glutMainLoop();                                         /* pass control to the main loop  */
}