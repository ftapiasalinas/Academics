/*This program to draw points, Lines and polygons*/
#include <GL/gl.h>
#include <GL/glut.h>
#define drawOneLine(x1,y1,x2,y2) glBegin(GL_LINES); glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();
void myinit(void)
{
  glClearColor(0.8, 0.8, 0.8, 0.0); /* gray background */
 
  glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  glLoadIdentity();                 /* position the "clipping rectangle" */
  gluOrtho2D( -750, 750, -750, 750);/* at -B/2, its right edge at +B/2, its bottom */
  glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}

void display( void )
{
     GLubyte fly[] = {
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x03, 0x80, 0x01, 0xC0, 0x06, 0xC0, 0x03, 0x60,
         0x04, 0x60, 0x06, 0x20, 0x04, 0x30, 0x0C, 0x20,
         0x04, 0x18, 0x18, 0x20, 0x04, 0x0C, 0x30, 0x20,
         0x04, 0x06, 0x60, 0x20, 0x44, 0x03, 0xC0, 0x22,
         0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
         0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
         0x44, 0x01, 0x80, 0x22, 0x44, 0x01, 0x80, 0x22,
         0x66, 0x01, 0x80, 0x66, 0x33, 0x01, 0x80, 0xCC,
         0x19, 0x81, 0x81, 0x98, 0x0C, 0xC1, 0x83, 0x30,
         0x07, 0xe1, 0x87, 0xe0, 0x03, 0x3f, 0xfc, 0xc0,
         0x03, 0x31, 0x8c, 0xc0, 0x03, 0x33, 0xcc, 0xc0,
         0x06, 0x64, 0x26, 0x60, 0x0c, 0xcc, 0x33, 0x30,
         0x18, 0xcc, 0x33, 0x18, 0x10, 0xc4, 0x23, 0x08,
         0x10, 0x63, 0xC6, 0x08, 0x10, 0x30, 0x0c, 0x08,
         0x10, 0x18, 0x18, 0x08, 0x10, 0x00, 0x00, 0x08
     };

  
     glClear (GL_COLOR_BUFFER_BIT);
     glColor3f (1.0, 0.0, 1.0);

     glEnable (GL_POLYGON_STIPPLE);
     glPolygonStipple (fly);
     glRectf (0.0, 0.0, 500.0, 500.0);
  
     glDisable (GL_POLYGON_STIPPLE);
     glFlush ();
}


int main(int argc, char** argv)
{
  glutInit(&argc,argv);                                   /*initialize the toolkit   */
  glutInitWindowSize( 1000, 1000 );                         /* Set window size */
  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);           /* Set the display mode */
  glutInitWindowPosition( 100, 100 );  
  glutCreateWindow("My Points");                          /* create window with title */
  
  glutDisplayFunc(display);                               /*tell OpenGL main loop what     */
  myinit();                                               /* set attributes                 */

  glutMainLoop();                                         /* pass control to the main loop  */
}
