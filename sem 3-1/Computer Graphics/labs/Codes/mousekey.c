/* Assignment - Mouse Keyboard interaction

 Submitted By
Mayur Mathur      Anadi Rastogi           Ayush Sinha
2011C6PS603G      2011C6PS034G            2011C6PS415G 


This program draws a pentagon by taking inputs from the user via mouse clicking and labels it 
by taking input from keyboard (the characters can be anything between a to z,if it is other than these a - will be seen).
User just have to input the characters and the labeling will be done in the order of the points which the user clicked on while making the pentagon
*/

#include <GL/gl.h>
#include <GL/glut.h>

int count=0;   //global variables
int i[100];
int j=-2;
  
  //Bitmap for A to Z
  GLubyte pix[36]={0x00, 0x00, 0xf0, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  GLubyte Z[36] = {0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff};        
  GLubyte Y[36] = {0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x14,0x00,0x22,0x00,0x41,0x00,0xc0,0xc0,};
  GLubyte X[36] = {0x80,0xc0,0x80,0x80,0x41,0x00,0x22,0x00,0x1c,0x00,0x08,0x00,0x14,0x00,0x22,0x00,0x41,0x00,0xc0,0xc0,};
  GLubyte W[36] = {0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3};
  GLubyte V[36] = {0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3}; 
  GLubyte U[36] = {0xff,0x00, 0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,};
  GLubyte T[36] = {0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0xff,0x00};
  GLubyte S[36] = {0xff,0x00,0x81,0x00,0x81,0x00,0x01,0x00,0x01,0x00,0xff,0x00,0x80,0x00,0x80,0x00,0x83,0x00,0xff,0x00};
  GLubyte R[36] = {0x8f,0x00,0x98,0x00,0xb0,0x00,0xe0,0x00,0xfc,0x00,0x84,0x00,0x84,0x00,0x84,0x00,0x84,0x00,0xfc,0x00};
  GLubyte Q[36] = {0xfe,0x00,0xc3,0x00,0xa5,0x00,0x92,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0xc3,0x00,0xfe,0x00}; 
  GLubyte P[36] = {0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0xfe,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0xFE,0x00}; 
  GLubyte O[36] = {0xfe,0x00,0xc6,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0xc6,0x00,0xFE,0x00}; 
  GLubyte N[36] = {0x83,0x00, 0x83,0x00,0x83,0x00,0x85,0x00,0x89,0x21,0x91,0x21,0xA1,0x21,0xc1,0x21,0xc1,0x21,0xc1,0x21}; 
  GLubyte M[36] = {0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0xb9,0x00,0xec,0x00,0xc6,0x00};
  GLubyte L[36] = {0xfe,0x00,0x81,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,};
  GLubyte K[36] = {0x83,0x00,0x86,0x00,0x8c,0x00,0x98,0x00,0xf0,0x00,0xf0,0x00,0x98,0x00,0x8c,0x00,0x86,0x00,0x83,0x00}; 
  GLubyte J[30] = {0xF8,0x00,0x88,0x00,0x88,0x00, 0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0xFE,0x00};
  GLubyte I[30] = {0xFE,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0xFE,0x00};
  GLubyte H[30] = {0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0x81,0x00,0xFF,0x00,0x81,0x00,0x81,0x00,0x81,0x00};
  GLubyte G[30] = {0xFE,0x00,0x81,0x00,0x91,0x00,0x9f,0x00,0x90,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0xFE,0x00};
  GLubyte F[30] = {0x80,0x00, 0x80,0x00,0x80,0x00,0x88,0x00,0xF8,0x00,0x88,0x00,0x80,0x00, 0xFE,0x00};
  GLubyte E[30] = {0xFE,0x00,0x81,0x00,0x80,0x00,0x80,0x00,0x88,0x00,0xF8,0x00,0x88,0x00,0x80,0x00,0xFE,0x00};
  GLubyte D[30] = {0xFE,0x00,0xc2,0x00,0xc2,0x00,0xc2,0x00,0xc2,0x00,0xc2,0x00,0xc2,0x00,0xc2,0x00,0xFE,0x00};
  GLubyte C[20] = {0xFE,0x00,0x81,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0xFE,0x00};
  GLubyte B[24] = {0xFE,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0xFE,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0xFE,0x00};
  GLubyte A[24] = {0x82,0x00,0x82,0x00,0x82,0x00,0x82,0x00,0xFE,0x00,0xFE,0x00, 0x82,0x00,0x82,0x00,0xFE,0x00,};

void myinit(void)
{
   glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
   glLoadIdentity();                 /* position the "clipping rectangle" */
   gluOrtho2D(0,1010, 650,0);        /* at -B/2, its right edge at +B/2, its bottom */
   glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
   glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
   glClearColor (1.0, 1.0, 1.0, 0.0); 
}

int store(int x,int y)             /* to store coordinates in an array */
{
   i[count]=x;
   i[count+1]=y;
   count=count+2;
   return count;
}

void display( char c ,int j )      /* to display characters */
{
   glColor3f (0.0, 0.0, 0.0);
   glRasterPos2i (i[j], i[j+1]);
               
   switch(c)           
   {
     case 'a':
     case 'A':         
     glBitmap (10, 10, 0.0, 0.0, 11.0, 0.0, A);
     break;
 
     case 'b':
     case 'B':         
     glBitmap (10, 10, 0.0, 0.0, 11.0, 0.0, B);
     break;

     case 'c':
     case 'C':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, C);
     break;

     case 'd':
     case 'D':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, D);
     break;

     case 'e':
     case 'E':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, E);
     break;

     case 'f':
     case 'F':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, F);
     break;

     case 'g':
     case 'G':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, G);
     break;

     case 'h':
     case 'H':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, H);
     break;

     case 'i':
     case 'I':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, I);
     break;
 
     case 'j':
     case 'J':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, J);
     break;

     case 'k':
     case 'K':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, K);
     break;

     case 'l':
     case 'L':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, L);
     break;

     case 'm':
     case 'M':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, M);
     break;

     case 'n':
     case 'N':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, N);
     break;

     case 'o':
     case 'O':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, O);
     break;

     case 'p':
     case 'P':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, P);
     break;

     case 'q':
     case 'Q':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, Q);
     break;

     case 'r':
     case 'R':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, R);
     break;

     case 's':
     case 'S':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, S);
     break;
   
     case 't':
     case 'T':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, T);
     break;

     case 'u':
     case 'U':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, U);
     break;
  
     case 'v':
     case 'V':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, V);
     break;
    
     case 'w':
     case 'W':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, W);
     break;

     case 'x':
     case 'X':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, X);
     break;
  
     case 'y':
     case 'Y':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, Y);
     break;

     case 'z':
     case 'Z':         
     glBitmap (10, 10, 0.0, 0.0, 1.0, 0.0, Z);
     break;
  
     default :
     glBitmap (10, 10, 0.0, 0.0, 12.0, 0.0, pix); //if user types any character other than these 26 chars
   }

   glFlush();                       /* send all commands */
}

void drawPentagon()   //Plotting the polygon
{
   glClear(GL_COLOR_BUFFER_BIT);     /*clear the window */    
   glColor3f(1.0f,0.0f,0.0f);
     
   glBegin(GL_POLYGON);       //To draw the pentagon
         glVertex2i(i[0],i[1]);
         glVertex2i(i[2],i[3]);
         glVertex2i(i[4],i[5]);
         glVertex2i(i[6],i[7]);
         glVertex2i(i[8],i[9]);
   glEnd();
 
   glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
   glLoadIdentity();                 /* in terms of World coordinates */
   glFlush();                           /* send all commands */
 
 }
void mousePlotting(int button,int state, int x,int y) // to take input from the mouse
{  
   int z=111;
   int c;
   glColor3f(0.0,0.0,1.0f);
   glPointSize(5.0);
   
   if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
     {
        printf("%d ", x);
        printf("%d " , y);
        c=store(x,y);
        glBegin(GL_POINTS);    //To draw points clicked by user  
           glVertex2i(x,y);
        glEnd();
     
        if(c==10)
         {
           drawPentagon();
         }
     }
   glFlush();                             /* send all commands */
   
   
}
void MyKey (GLubyte key, GLint x, GLint y)   //To take input fom keyboard
{   
   int z=111;
   printf("%c ", key);
   char c=key;
   j=j+2;
   display(c,j);
   glFlush();                            /* send all commands */
}


void main(int argc, char** argv)
{
   glutInit(&argc,argv);                                   /*initialize the toolkit   */
   glutInitWindowSize( 1010,650  );                         /* Set window size */
   glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);           /* Set the display mode */
   glutInitWindowPosition( 0, 0 );  
   glutCreateWindow("Pentagon Drawing ");                          /* create window with title */
   glutDisplayFunc(drawPentagon);                               /*tell OpenGL main loop what     */
   myinit();     
   glutMouseFunc(mousePlotting);                            /* set attributes                 */
   glutKeyboardFunc(MyKey);                                  /* set attributes                 */  
   glutMainLoop();                                         /* pass control to the main loop  */
}
