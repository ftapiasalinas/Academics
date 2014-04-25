#include <GL/gl.h>
#include <GL/glut.h>
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
 glClear(GL_COLOR_BUFFER_BIT);     /*clear the window */
 glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
 glLoadIdentity();                 /* in terms of World coordinates */
 int X = 9, Y = 0;
 
 GLubyte bitShapeA[8] = {0x84 ,0x84,0x84,0x78 ,0x48, 0x48,0x30,0x30 };
 GLubyte bitShapeB[8] = {0x78 ,0x48,0x48,0x78 ,0x48, 0x48,0x78 };
 GLubyte bitShapeC[8] = {0x78 ,0x82,0x80,0x80 ,0x80, 0x42,0x38 };
 GLubyte bitShapeD[8] = {0x70 ,0x48,0x44,0x44,0x44, 0x44,0x48,0x70 };
 GLubyte bitShapeE[8] = {0x7c ,0x40,0x40,0x78,0x78, 0x40,0x40,0x7c };
// GLubyte bitShapel[8] = {0x80,0x80,0x40,0x40,0x20,0x20,0x10,0x10};
// GLubyte bitShapeA[8] = {0x00,0x40,0x42,0x2d,0x24,0x14,0x18,0x18};
 //GLubyte bitShapeL[16] = {0x800 ,0x400,0x400,0x200 ,0x100, 0x080,0x080,0x040,0x020,0x010,0x010,0x008,0x004,0x002,0x002,0x001 };
 glPixelStorei (GL_UNPACK_ALIGNMENT,1); 
 glRasterPos2i(50,50);
 glColor3f(1.0, 0.0, 0.0);
 glBitmap (6,8, 0.0, 0.0, X, Y, bitShapeA); 
 glBitmap (6,8, 0.0, 0.0, X, Y, bitShapeB);                    
  glBitmap (6,8, 0.0, 0.0, X, Y, bitShapeC); 
glBitmap (6,8, 0.0, 0.0, X, Y, bitShapeD);                    
glBitmap (6,8, 0.0, 0.0, X, Y, bitShapeE);                   
 glFlush();                       /* send all commands */
}
void MyKey (GLubyte key, GLint x, GLint y)
{
     int z=111;
     printf("%c ", key);
     printf("%d ", x);
     printf("%d " , y);
       
     printf("%d\n",glutGetModifiers()); 
     glFlush();
}

void main(int argc, char** argv)
{
  glutInit(&argc,argv);                                   /*initialize the toolkit   */
  glutInitWindowSize( 1000, 1000 );                         /* Set window size */
  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);           /* Set the display mode */
  glutInitWindowPosition( 100, 100 );  
  glutCreateWindow("My Points");                          /* create window with title */
  glutDisplayFunc(display);                               /*tell OpenGL main loop what     */
  myinit();                                               /* set attributes                 */
  /*glutKeyboardFunc( MyKey);*/
  glutMainLoop();                                         /* pass control to the main loop  */
}
