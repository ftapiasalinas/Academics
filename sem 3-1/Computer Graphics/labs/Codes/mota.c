/*This program to draw points, Lines and polygons*/
#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

#define PI 3.1415926535898
#define DEG2RAD 3.14159/180.0

void reflectX(GLdouble[][2],int,int);
void reflectY(GLdouble[][2],int,int);
void reflectXeqY(GLdouble[][2],int);
void fencing(int);
void house(void); 
void path();
void above_hut();

void myinit(void)
{
  glClearColor(0.8, 0.8, 0.8, 0.0); /* gray background */
 
  glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
  glLoadIdentity();                 /* position the "clipping rectangle" */
  gluOrtho2D( -750, 750, -750, 750);/* at -B/2, its right edge at +B/2, its bottom */
  glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
}

void green(void);
void blue(void);
void drawellipse(float , float ,int , int , int , float, float);
void drawcloud(float , float , float , float);
void drawcircle(float , float , float, int) ;


void display( void )
{
     int i;
  glClear(GL_COLOR_BUFFER_BIT);     /*clear the window */
  gl
  glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
  glLoadIdentity();                 /* in terms of World coordinates */
  for(i=0;i<17;i++)
   fencing(i*90);    
  /* glBegin(GL_QUADS);
   glColor3f(0.62,0.32,0.17);
    glVertex2i( -660,-20 );
      glVertex2i(-600,-20);
      glVertex2i(-600,05);         
      glVertex2i( -660, 05);
      glVertex2i( -660,150 );
      glVertex2i(-600,150);
      glVertex2i(-600,125);         
      glVertex2i( -660, 125);                   
 glEnd();*/
           green();
           //blue();
           //glColor3f(0.529,0.81,0.92);
           glColor3f ( 0, 0.74, 1);
     drawcloud(-500,600,150,60);
     drawcloud(500,600,150,60);
     drawcloud(10,400,0.8*150,0.6*60);
         house();
         path();
         above_hut();

  glFlush(); /* send all commands */
}
void green()
{
     glLoadIdentity();
     glBegin(GL_QUADS);
      glColor3f ( 0.48, 0.98, 0);       
      glVertex2i( -750,-50 );
      glVertex2i(750,-50);
      glVertex2i(750,-750);         
      glVertex2i( -750, -750 );
      glEnd();
      }
     
void blue()
{
     glLoadIdentity();
     glBegin(GL_QUADS);
      glColor3f ( 0, 0.74, 1);       
      glVertex2i( -750,190 );
      glVertex2i(750,190);
      glVertex2i(750,750);         
      glVertex2i( -750, 750 );
      glEnd();
      }
      
void drawellipse(float x, float y,int dispx, int dispy, int filled, float radiusX, float radiusY)
{
   if(filled)
   {   
       int i;
       glBegin(GL_POLYGON);
       for(i=0;i<360;i++)
       {
          float rad = i*DEG2RAD;
          glVertex2f(x+dispx+cos(rad)*radiusX,
                      y+dispy+sin(rad)*radiusY);
       }
       glEnd();
   }
   else
   {
       int i;
       glBegin(GL_LINE_STRIP);
       for(i=0;i<360;i++)
       {
          float rad = i*DEG2RAD;
          glVertex2f(x+dispx+cos(rad)*radiusX,
                      y+dispy+sin(rad)*radiusY);
       }
       glEnd();
   }   
}

void drawcloud(float x, float y, float radiusX, float radiusY)
{
     int i,k=0;
     float a,b;
     drawellipse(x,y,0,0,1,radiusX,radiusY);

     glBegin(GL_POLYGON);
     for(i=0;i<360;i++)
     {
        float rad = i*DEG2RAD;
	a=x+cos(rad)*radiusX;
	b=y+sin(rad)*radiusY;
	k++;
	if(k==30)
	{
	     drawcircle(a,b,radiusY/3+20,100);
	     k=0;
	}
	
     }
     glEnd();
     drawellipse(x,y,0,0,1,radiusX,radiusY);

}

void drawcircle(float cx, float cy, float r, int num_segments) 
{ 
    glBegin(GL_POLYGON);
    int ii; 
    for(ii = 0; ii < num_segments; ii++) 
    { 
        float theta = 2.0f * 3.1415926f * (float)(ii) / (float)(num_segments);//get the current angle 

        float x = r * cosf(theta);//calculate the x component 
        float y = r * sinf(theta);//calculate the y component 
        glVertex2f(x + cx, y + cy);//output vertex 
    } 
    glEnd(); 
}

void above_hut()
{
    glLoadIdentity();
    glBegin(GL_TRIANGLES);
    glColor3f ( 1, 0.27, 0);       
      glVertex2i( -450,200 );
      glVertex2i(-365,450);
      glVertex2i(-280,200);
      glEnd();
      
      }

void path()
{    
     glLoadIdentity();
     glBegin(GL_QUADS);
     glColor3f ( 0.82, 0.41, 0.11);       
      glVertex2i( -420,-60 );
      glVertex2i(-310,-60);
      glVertex2i(-180,-750);         
      glVertex2i( -550, -750 );
      glEnd();
}

void fencing(int x)
{
 glLoadIdentity();  
 glTranslatef(x,0,0);  
 glBegin(GL_QUADS) ; 
                  
      glColor3f ( 0.55, 0.27, 0.07);       
      glVertex2i( -680,-50 );/*This program to draw points, Lines and polygons*/
 
void myinit(void)
{
      glClearColor(0.94, 0.81, 0.99 ,1); /*  gray background */
      glMatrixMode(GL_PROJECTION);      /* In World coordinates: */
      glLoadIdentity();                 /* position the "clipping rectangle" */
      gluOrtho2D( -750,750, -750, 750); /* at -B/2, its right edge at +B/2, its bottom */
      glMatrixMode(GL_MODELVIEW);       /* edge at -B/2 and its top edge at +B/2 */
	
}

#define DEG2RAD 3.14159/180.0

void fencing(int x)
{
 
// glTranslatef(x,0,0);  
 glBegin(GL_QUADS) ; 
                  
      glColor3f ( 0.55, 0.27, 0.07);       
      glVertex2i( -680+x,-50 );
      glVertex2i(-660+x,-50);
      glVertex2i(-660+x,190);         
      glVertex2i( -680+x, 190 );
      glColor3f ( 0.62, 0.32, 0.17); 
      glVertex2i( -750+x,-20 );
      glVertex2i(-680+x,-20);
      glVertex2i(-680+x,05);         
      glVertex2i( -750+x, 05);
      glVertex2i( -750+x,150 );
      glVertex2i(-680+x,150);
      glVertex2i(-680+x,125);         
      glVertex2i( -750+x, 125);
      
      glEnd(); 
}
void house()
{
            glLoadIdentity();
            glBegin(GL_QUADS);
            glColor3f(0.5,0,0);
            glVertex2i( -450,-60 );
            glVertex2i(-280,-60);
            glVertex2i(-280,200);         
            glVertex2i( -450, 200);
            glColor3f(0.69,0.13,0.13);
            glVertex2i( -390,-60 );
            glVertex2i(-340,-60);
            glVertex2i(-340,50);         
            glVertex2i( -390, 50);
            glColor3f(1,0.27,0);
            glVertex2i( -430,170 );
            glVertex2i(-410,170);
            glVertex2i(-410,130);         
            glVertex2i( -430, 130);
            glColor3f(1,0.27,0);
            glVertex2i( -300,170 );
            glVertex2i(-320,170);
            glVertex2i(-320,130);         
            glVertex2i( -300, 130);
            glEnd();
}
 void above_hut()
{
    glLoadIdentity();
    glBegin(GL_TRIANGLES);
    glColor3f ( 1, 0.27, 0);       
      glVertex2i( -450,200 );
      glVertex2i(-365,450);
      glVertex2i(-280,200);
      glEnd();
      
      }

void path()
{    
     glLoadIdentity();
     glBegin(GL_QUADS);
     glColor3f ( 0.82, 0.41, 0.11);       
      glVertex2i( -420,-60 );
      glVertex2i(-310,-60);
      glVertex2i(-180,-750);         
      glVertex2i( -550, -750 );
      glEnd();
}


 
void drawellipse(float x, float y,int dispx, int dispy, int filled, float radiusX, float radiusY)
{
   if(filled)
   {   
       int i;
       glBegin(GL_POLYGON);
       for(i=0;i<360;i++)
       {
          float rad = i*DEG2RAD;
          glVertex2f(x+dispx+cos(rad)*radiusX,
                      y+dispy+sin(rad)*radiusY);
       }
       glEnd();
   }
   else
   {
       int i;
       glBegin(GL_LINE_STRIP);
       for(i=0;i<360;i++)
       {
          float rad = i*DEG2RAD;
          glVertex2f(x+dispx+cos(rad)*radiusX,
                      y+dispy+sin(rad)*radiusY);
       }
       glEnd();
   }   
}
void drawcircle(float cx, float cy, float r, int num_segments) 
{ 
    glBegin(GL_POLYGON);
    int ii; 
    for(ii = 0; ii < num_segments; ii++) 
    { 
        float theta = 2.0f * 3.1415926f * (float)(ii) / (float)(num_segments);//get the current angle 

        float x = r * cosf(theta);//calculate the x component 
        float y = r * sinf(theta);//calculate the y component 
        glVertex2f(x + cx, y + cy);//output vertex 
    } 
    glEnd(); 
}


void spiral(double cx, double cy, int dispx, int dispy, int xscale, int yscale, int n)
{    
     glBegin(GL_LINE_STRIP);
         double theta = 0;
         double r;
         while(theta<n*PI)
         {         
             r = 3*sqrt(theta);
             double x = cx + r*cos(theta);
             double y = cy + r*sin(theta);
             glColor3f(0,0,1);
             glVertex2f(xscale*x+dispx,yscale*y+dispy);
             theta+=PI/20;
         } 
      glEnd();     
}

void drawarc(float cx, float cy, float r, float start_angle, int filled, float arc_angle, int num_segments)
{    
   if(filled)
   {
     start_angle = start_angle*3.14/180;
     arc_angle = arc_angle*3.14/180;
     float theta = arc_angle / (float)(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open
     float tangetial_factor = tanf(theta);
     float radial_factor = cosf(theta);  
     float x = r * cosf(start_angle);//we now start at the start angle
     float y = r * sinf(start_angle);
     glBegin(GL_POLYGON);//since the arc is not a closed curve, this is a strip now
     int ii;
     for(ii = 0; ii < num_segments; ii++)
     {
         //  glColor3f(1,1,0);
        glVertex2f(x + cx, y + cy);
    
        float tx = -y;
        float ty = x;
        
        x += tx * tangetial_factor;
        y += ty * tangetial_factor;
        
        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
   } 
   else
   {
        start_angle = start_angle*3.14/180;
     arc_angle = arc_angle*3.14/180;
     float theta = arc_angle / (float)(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open
     float tangetial_factor = tanf(theta);
     float radial_factor = cosf(theta);  
     float x = r * cosf(start_angle);//we now start at the start angle
     float y = r * sinf(start_angle);
     glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
     int ii;
     for(ii = 0; ii < num_segments; ii++)
     {
         //  glColor3f(1,1,0);
        glVertex2f(x + cx, y + cy);
    
        float tx = -y;
        float ty = x;
        
        x += tx * tangetial_factor;
        y += ty * tangetial_factor;
        
        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();  
   }
}  

void drawspirals()
{
     glColor3f(0,0.8,0.9);
     drawellipse(-550,-430,-100,-40,1,100,50);
     spiral(-55,-110,-100,-40,10,4,5);
     
     glColor3f(0,0.8,0.9);
     drawellipse(-550,-430,650,80,1,100,50);
     spiral(-55,-110,650,80,10,4,5);
     
     glColor3f(0,0.8,0.9);
     drawellipse(-550,-430,700,-120,1,100,50);
     spiral(-55,-110,700,-120,10,4,5);
}

void drawcloud(float x, float y, float radiusX, float radiusY)
{
     int i,k=0;
     float a,b;
     drawellipse(x,y,0,0,1,radiusX,radiusY);

     glBegin(GL_POLYGON);
     for(i=0;i<360;i++)
     {
        float rad = i*DEG2RAD;
	a=x+cos(rad)*radiusX;
	b=y+sin(rad)*radiusY;
	k++;
	if(k==30)
	{
	     drawcircle(a,b,radiusY/3+20,100);
	     k=0;
	}
	
     }
     glEnd();
     drawellipse(x,y,0,0,1,radiusX,radiusY);

}



void creflecty(int a, int n, double pt[][2], double o[][2])
{
     int i;
     for(i=0;i<n;i++)
     {
         o[i][0] = 2*a-pt[i][0];
         o[i][1] = pt[i][1];
     }    
}

void drawcylinder(float cx, float cy, float length)
{
     float ax,bx;
     ax = cx - 20;
     bx = cx + 20;
     glBegin(GL_QUADS);
	 glVertex2i(ax,cy-(length/2));
	 glVertex2i(bx,cy-(length/2));
	 glVertex2i(bx,cy+(length/2));
	 glVertex2i(ax,cy+(length/2));
     glEnd();

     drawarc(cx,cy+(length/2),20,180,1,-180,100);
     drawarc(cx,cy-(length/2),20,-180,1,180,100);


}

void drawrest3(double x, double y)
{
	double temp1 = -x;
	double temp2 = y;
	drawellipse(temp1, temp2, 0,0,1,6, 15);
	//drawellipse(temp1, -temp2, 0,0,1,6, 15);
	drawellipse(-temp1, temp2, 0,0,1,6, 15);
}

void rains()
{
int i=0;
for(i=0;i<=100;i++)
{
    glColor3f(0.596078,0.596078,0.9955);
	double num1 = rand()%1500;
	double num2 = rand()%1500;
	drawellipse(num1, num2, 0,0,1,6, 15);
	drawrest3(num1, num2);
	}
}


void drawtree()
{
     //glColor3f();
    // glRectf(100, 350, 180, -200);
     glColor3f(0,0.6,0);
     drawcloud(140,500,100,120);
     
          	 glLineWidth(10.00);
     	glBegin(GL_LINES);

  glColor3f ( 0.62, 0.32, 0.17); 
	     glVertex2i(120,380);
	     glVertex2i(140,480);
     	glEnd();
     	 glLineWidth(1.00);
     
}

void drawgirl()
{

//hand
glColor3f(0.647059,0.164706,0.164706);
drawellipse(475,-135,0,0,1,75,35);
glColor3f(0.8,0.8,0.8);
drawellipse(475,-135,0,0,1,55,25);
glColor3f(0,0,0);
drawellipse(475,-135,0,0,0,75,35);
drawellipse(475,-135,0,0,0,55,25);
//hand

	glColor3f(1,1,0);
	drawellipse(385,-135,0,0,1,25,62.5);
	glColor3f(0,0,0);
	drawellipse(385,-135,0,0,0,25,62.5);
	glBegin(GL_QUADS);
	     glColor3f(1,1,0);
	     glVertex2i(500,-72.5);
	     glVertex2i(500,-197.5);
	     glVertex2i(387.5,-197.5);
	     glVertex2i(387.5,-72.5);
	glEnd();
	glBegin(GL_LINES);
	     glColor3f(0,0,0);
	     glVertex2i(500,-72.5);
	     glVertex2i(500,-197.5);
	     glVertex2i(500,-197.5);
	     glVertex2i(387.5,-197.5);
	glEnd();


        glColor3f(1,0.5,0.5);
	drawarc(455,-95,135,180,1,-180,100);
	glColor3f(0,0,0);
	drawarc(455,-95,135,180,0,-180,100);
	glColor3f(0.8,0.8,0.8);
	drawarc(342.5,-95,22.5,180,1,-180,100);
	glColor3f(1,1,0);
	drawarc(387.5,-95,22.5,180,1,-180,100);
	drawarc(432.5,-95,22.5,180,1,-180,100);
	drawarc(477.5,-95,22.5,180,1,-180,100);
	glColor3f(0.8,0.8,0.8);
	drawarc(522.5,-95,22.5,180,1,-180,100);
	drawarc(567.5,-95,22.5,180,1,-180,100);

	glColor3f(0,0,0);
	drawarc(342.5,-95,22.5,180,0,-180,100);
	drawarc(387.5,-95,22.5,180,0,-180,100);
	drawarc(432.5,-95,22.5,180,0,-180,100);
	drawarc(477.5,-95,22.5,180,0,-180,100);
	drawarc(522.5,-95,22.5,180,0,-180,100);
	drawarc(567.5,-95,22.5,180,0,-180,100);
 


	glBegin(GL_QUADS);
	  glColor3f(0,0,0);
	  glVertex2i(435,-72.5);
	  glVertex2i(445,-72.5);
 	  glVertex2i(457,-137);
 	  glVertex2i(447,-137);
	glEnd();

//hand	
	glColor3f(0.647059,0.164706,0.164706);
	drawellipse(450,-136,0,0,1,10,5);
	drawellipse(453,-146,0,0,1,11,5);	
	drawellipse(460,-152,0,0,1,11,5);
	glColor3f(0,0,0);
	drawellipse(450,-136,0,0,0,10,5);
	drawellipse(453,-146,0,0,0,11,5);
	drawellipse(460,-152,0,0,0,11,5);

	glBegin(GL_QUADS);
	     glColor3f(0.647059,0.164706,0.164706);
	     glVertex2i(368,-180);
	     glVertex2i(374,-193);
	     glVertex2i(450,-153);
	     glVertex2i(450,-135);
	
	glEnd();
        
	glBegin(GL_LINES);
	     glColor3f(0,0,0);
	     glVertex2i(368,-180);
	     glVertex2i(374,-193);
	     
	     glVertex2i(374,-193);
	     glVertex2i(448.5,-155);
	     glVertex2i(440,-140);
	     glVertex2i(368,-180);
	glEnd();
//hand

	glBegin(GL_LINES);
	     glColor3f(0,0,0);
	     glVertex2i(455,40);
	     glVertex2i(362,-95);
	     glVertex2i(455,40);
	     glVertex2i(410,-95);
	     glVertex2i(455,40);
	     glVertex2i(455,-95);
	     glVertex2i(455,40);
	     glVertex2i(500,-95);
	     glVertex2i(455,40);
	     glVertex2i(548,-95);

	     glVertex2i(455,40);
	     glVertex2i(455,60);
	     glVertex2i(454,40);
	     glVertex2i(454,60);
	     glVertex2i(456,40);
	     glVertex2i(456,60);

	glEnd();
//skirt
	glBegin(GL_QUADS);
	  glColor3f(1,0,0);
	  glVertex2i(500,-197.5);
	  glVertex2i(520,-345);
	  glVertex2i(335,-345);
	  glVertex2i(380,-197.5);
	glEnd();

	glBegin(GL_LINES);
	  glColor3f(0,0,0);
	  glVertex2i(500,-197.5);
	  glVertex2i(520,-345);
	  glVertex2i(520,-345);
	  glVertex2i(335,-345);
	  glVertex2i(335,-345);
	  glVertex2i(380,-197.5);
	glEnd();
//skirt

//legs
	glColor3f(0.647059,0.164706,0.164706);
	drawellipse(395,-500,0,0,1,25,13);
	drawellipse(515,-470,0,0,1,25,13);

	glColor3f(0,0,0);
	drawellipse(395,-500,0,0,0,25,13);
	drawellipse(515,-470,0,0,0,25,13);

	glBegin(GL_LINES);
	  glColor3f(0,0,0);
	  glVertex2i(390,-345);
	  glVertex2i(370,-505);
	  
	  glVertex2i(403,-345);
	  glVertex2i(384,-497);
	  
	  glVertex2i(460,-345);
	  glVertex2i(490,-475);
	
	  glVertex2i(473,-345);
	  glVertex2i(501.5,-465);
	glEnd();

	glBegin(GL_QUADS);
	  glColor3f(0.647059,0.164706,0.164706);
	  glVertex2i(390,-345);
	  glVertex2i(370,-505);
	  glVertex2i(383,-505);	  
	  glVertex2i(403,-345);

	  
	  glVertex2i(460,-345);
	  glVertex2i(490,-475);
	  glVertex2i(503,-475);	
	  glVertex2i(473,-345);

	glEnd();
}

void display(void)
{
     glClear(GL_COLOR_BUFFER_BIT);     /*clear the window */
     glMatrixMode(GL_MODELVIEW);       /* The following coordinates are expressed */
     glLoadIdentity();                 /* in terms of World coordinates */
     int i;
    
     GLfloat x = 5;                  
     glPointSize(x);
     glEnable(GL_POINT_SMOOTH);
     //drawfence(0.6);
     glColor3f(0.576471 , 0.858824,0.439216);
     glRectf(-750,-80*.6,750,-750);
     rains();
     glColor3f(0.529,0.81,0.92);
     drawcloud(-500,600,150,60);
     drawcloud(500,600,150,60);
     drawcloud(10,400,0.8*150,0.6*60);
    
    // cdrawhouse(0.8,15,-20);
     drawtree();
     drawspirals();
     //drawpath(0.8,15,-20);
     
      for(i=0;i<17;i++)
        fencing(i*90); 
        house();
        above_hut();
        path();
          drawgirl();
    
     glPointSize(10.0);
     glVertex2f(100,100);
     glFlush();
                           /* send all commands */
}

void reflectX(double points[][2], int a, int n)
{
     glBegin(GL_LINE_STRIP);
         int i;
         for(i=0;i<n;i++)
         {
             glVertex2f(points[i][0],2*a-points[i][1]);
         }
     glEnd();
}

void reflectY(double points[][2], int a, int n)
{
     glBegin(GL_LINE_STRIP);
         int i;
         for(i=0;i<n;i++)
         {
             glVertex2f(2*a-points[i][0], points[i][1]);
         }
     glEnd();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);                                   /*initialize the toolkit   */
    glutInitWindowSize( 500, 500 );                         /* Set window size */
    glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);           /* Set the display mode */
    glutInitWindowPosition( 500, 100 );  
    glutCreateWindow("My First Graphics Program in OpenGL");                          /* create window with title */
    glutDisplayFunc(display);                               /*tell OpenGL main loop what     */
    myinit();                                               /* set attributes                 */
    glutMainLoop(); 
    return(0);                                        /* pass control to the main loop  */
}

      glVertex2i(-660,-50);
      glVertex2i(-660,190);         
      glVertex2i( -680, 190 );
      glColor3f ( 0.62, 0.32, 0.17); 
      glVertex2i( -750,-20 );
      glVertex2i(-680,-20);
      glVertex2i(-680,05);         
      glVertex2i( -750, 05);
      glVertex2i( -750,150 );
      glVertex2i(-680,150);
      glVertex2i(-680,125);         
      glVertex2i( -750, 125);
      
      glEnd(); 
}
void house()
{
            glLoadIdentity();
            glBegin(GL_QUADS);
            glColor3f(0.5,0,0);
            glVertex2i( -450,-60 );
            glVertex2i(-280,-60);
            glVertex2i(-280,200);         
            glVertex2i( -450, 200);
            glColor3f(0.69,0.13,0.13);
            glVertex2i( -390,-60 );
            glVertex2i(-340,-60);
            glVertex2i(-340,50);         
            glVertex2i( -390, 50);
            glColor3f(1,0.27,0);
            glVertex2i( -430,170 );
            glVertex2i(-410,170);
            glVertex2i(-410,130);         
            glVertex2i( -430, 130);
            glColor3f(1,0.27,0);
            glVertex2i( -300,170 );
            glVertex2i(-320,170);
            glVertex2i(-320,130);         
            glVertex2i( -300, 130);
            glEnd();
}
            

void main(int argc, char** argv)
{
  glutInit(&argc,argv);                                   /*initialize the toolkit   */
  glutInitWindowSize( 500, 500 );                         /* Set window size */
  glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);           /* Set the display mode */
  glutInitWindowPosition( 500, 100 );  
  glutCreateWindow("My First Graphics Program in OpenGL");                          /* create window with title */
    
  glutDisplayFunc(display);                               /*tell OpenGL main loop what     */
  myinit();                                               /* set attributes                 */

  glutMainLoop();                                         /* pass control to the main loop  */
}
