/*This program to draw points, Lines and polygons*/
#include <GL/gl.h>
#include <GL/glut.h>
void myinit(void)
{
  glClearColor(0.8, 0.8, 0.8, 0.0); /* gray background */
 
  glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  glLoadIdentity();                 /* position the "clipping rectangle" */
  gluOrtho2D( -683, 683,-352, 352);/* at -B/2, its right edge at +B/2, its bottom */
  glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}


int Px[5];
int Py[5];
int j=0;
char c[5];

void mouselist(GLint button, GLint state, GLint x, GLint y)
{
     
     if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && j<5)
       {
          Px[j]=x-683;
          Py[j]=-y+352;
          j++;
          glutPostRedisplay();
       }
       
} 
void drawlines()
{
   glBegin(GL_LINE_LOOP);
     glColor3f( 0.55, 0.27, 0.07);       
     glVertex2i(Px[0],Py[0]);
     glVertex2i(Px[1],Py[1]);
     glVertex2i(Px[2],Py[2]);
     glVertex2i(Px[3],Py[3]);
     glVertex2i(Px[4],Py[4]);
 //glVertex2i(Px[0],Py[0]);
  glEnd();
     
     
}

void drawbitmap()
{
    int s; 
       GLubyte bitShapeA[8] = {0x84 ,0x84,0x84,0x78 ,0x48, 0x48,0x30,0x30 };
 GLubyte bitShapeB[8] = {0x78 ,0x48,0x48,0x78 ,0x48, 0x48,0x78 };
 GLubyte bitShapeC[8] = {0x78 ,0x82,0x80,0x80 ,0x80, 0x42,0x38 };
 GLubyte bitShapeD[8] = {0x70 ,0x48,0x44,0x44,0x44, 0x44,0x48,0x70 };
 GLubyte bitShapeE[8] = {0x7c ,0x40,0x40,0x78,0x78, 0x40,0x40,0x7c };
// GLubyte bitShapel[8] = {0x80,0x80,0x40,0x40,0x20,0x20,0x10,0x10};
// GLubyte bitShapeA[8] = {0x00,0x40,0x42,0x2d,0x24,0x14,0x18,0x18};
 //GLubyte bitShapeL[16] = {0x800 ,0x400,0x400,0x200 ,0x100, 0x080,0x080,0x040,0x020,0x010,0x010,0x008,0x004,0x002,0x002,0x001 };

 glPixelStorei (GL_UNPACK_ALIGNMENT,1); 
 glRasterPos2i(0,0);
 glColor3f(1.0, 0.0, 0.0);
 for(s=0;s<5;s++)
 {
      if(c[s]=='A' || c[s]=='a')
          glBitmap (6,8,-Px[s]+10,-Py[s]+10, 0, 0, bitShapeA); 
      else if(c[s]=='B' || c[s]=='b')
          glBitmap (6,8,-Px[s]+10,-Py[s]+10, 0, 0, bitShapeB);                    
      else if(c[s]=='C' || c[s]=='c')
          glBitmap (6,8,-Px[s]+10,-Py[s]+10, 0, 0, bitShapeC);                     
      else if(c[s]=='D' || c[s]=='d')    
          glBitmap (6,8,-Px[s]+10,-Py[s]+10, 0, 0, bitShapeD);                    
      else if(c[s]=='E' || c[s]=='e')    
          glBitmap (6,8, -Px[s]+10,-Py[s]+10, 0, 0, bitShapeE);
  } 
}

void display( void )
{
  glClear(GL_COLOR_BUFFER_BIT);     /*clear the window */
 
  glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
  glLoadIdentity();                 /* in terms of World coordinates */
  glPointSize(5.00);
 glBegin(GL_POINTS);
   glColor3f( 0.4, 0.2, 0);
   if(j>0)       
     glVertex2i(Px[0],Py[0]);
   if(j>1)  
     glVertex2i(Px[1],Py[1]);
   if(j>2)
     glVertex2i(Px[2],Py[2]);
   if(j>3)
     glVertex2i(Px[3],Py[3]);
   if(j>4)
     glVertex2i(Px[4],Py[4]);
   glEnd();
  if(j>=5)
  {
   drawbitmap();
   drawlines();
   }
  glFlush();                       /* send all commands */
}


void main(int argc, char** argv)
{
  glutInit(&argc,argv);                                   /*initialize the toolkit   */
  glutInitWindowSize( 1360,700);                         /* Set window size */
  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);           /* Set the display mode */
  glutInitWindowPosition( 0, 0 );  
  glutCreateWindow("My First Graphics Program in OpenGL");                          /* create window with title */
   int i;
   printf("Enter the 5 characters A,B,C,D,E -\n");
   for(i=0;i<5;i++)
   {
       scanf(" %c",&c[i]);
   } 
   printf("NOTE :CLICK in the order of vertices of the pentagon and the labels will be displayed accordingly\n");
   printf("enter 1 to continue");
     scanf(" %[^\n]c",&i);
   //printf("%c",c[4]);
   glutMouseFunc(mouselist);
  glutDisplayFunc(display);                               /*tell OpenGL main loop what     */
  myinit();                                                         /* set attributes                 */

  glutMainLoop();                                            /* pass control to the main loop  */
}
