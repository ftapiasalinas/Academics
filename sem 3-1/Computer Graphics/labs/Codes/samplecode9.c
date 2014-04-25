#include <GL/gl.h>
#include <GL/glut.h>
GLfloat X = 0.0f; // Translate screen to x direction (left or right) 
GLfloat Y = 0.0f; // Translate screen to y direction (up or down) 
void init(void) { 
     glClearColor (0.0, 0.0, 0.0, 0.0); 
     glShadeModel (GL_FLAT); 
} 
void display(void) 
{ 
     glClear (GL_COLOR_BUFFER_BIT); 
     glLoadIdentity (); 
     gluLookAt (10.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0, 1.0, 0.0); 
     static GLfloat vertices[]={      0.0f, 1.0f, 0.0f, 
                                      -1.0f,-1.0f, 1.0f, 
                                      1.0f,-1.0f, 1.0f, 
                                      0.0f, 1.0f, 0.0f, 
                                      1.0f,-1.0f, 1.0f, 
                                      1.0f,-1.0f,-1.0f, 
                                      0.0f, 1.0f, 0.0f, 
                                      1.0f,-1.0f,-1.0f, 
                                      -1.0f,-1.0f,-1.0f, 
                                      0.0f, 1.0f, 0.0f, 
                                      -1.0f,-1.0f,-1.0f, 
                                      -1.0f,-1.0f, 1.0f}; 
     static GLfloat color[]={1.0, 0.0, 0.0, 
                                  1.0, 0.0, 0.0, 
                                  1.0, 0.0, 0.0, 
                                  1.0, 1.0, 0.0, 
                                  1.0, 1.0, 0.0, 
                                  1.0, 1.0, 0.0, 
                                  1.0, 0.0, 1.0, 
                                  1.0, 0.0, 1.0, 
                                  1.0, 0.0, 1.0, 
                                  1.0, 1.0, 1.0, 
                                  1.0, 1.0, 1.0, 
                                  1.0, 1.0, 1.0}; 
     glPolygonMode (GL_BACK, GL_POINT); 
     //glCullFace(GL_BACK); //glEnable(GL_CULL_FACE) 
     while(1){ 
               glRotatef(5.0f, 0.0f, 1.0f, 0.0f); // rotate 45? around x & y axis 
               //glRotatef(0.0f, 0.0f, 1.0f, 145.0f); 
               // rotate 45? around x & y axis ; 
               glEnableClientState(GL_COLOR_ARRAY); 
               glEnableClientState(GL_VERTEX_ARRAY); 
               glColorPointer(3,GL_FLOAT,0,color); 
               glVertexPointer(3,GL_FLOAT,0,vertices); 
               glBegin(GL_POLYGON); 
                  glArrayElement(0); 
                  glArrayElement(1); 
                  glArrayElement(2); 
                  glArrayElement(3); 
                  glArrayElement(4);
                  glArrayElement(5);
                  glArrayElement(6); 
                  glArrayElement(7); 
                  glArrayElement(8); 
                  glArrayElement(9); 
                  glArrayElement(10); 
                  glArrayElement(11); 
               glEnd(); 
               sleep(100); 
               glFlush (); 
               glDisableClientState(GL_COLOR_ARRAY); 
               glDisableClientState(GL_VERTEX_ARRAY); 
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
    glutInitWindowSize (500, 500); glutInitWindowPosition (100, 100); glutCreateWindow (argv[0]); init (); glutDisplayFunc(display); glutReshapeFunc(reshape); glutMainLoop(); return 0; } 
