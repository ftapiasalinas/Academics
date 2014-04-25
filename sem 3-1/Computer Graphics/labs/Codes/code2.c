CODE 1

glEnable(GL_POINT_SMOOTH);
glPointSize(5);

glBegin(GL_POINTS);
      glVertex2i(0,0);
glEnd();
glEnable (GL_LINE_STIPPLE);
glLineStipple (3, 0xF0F0); /* dotted */
drawOneLine (0, 0, 160, 0);

CODE 1

glEnable (GL_LINE_STIPPLE);
glLineStipple (1, 0x0101); /* dotted */
drawOneLine (50.0, 125.0, 150.0, 125.0);

CODE 1

glLineWidth (5.0);
glLineStipple (1, 0x0101); /* dotted */
drawOneLine (50.0, 100.0, 150.0, 100.0);

