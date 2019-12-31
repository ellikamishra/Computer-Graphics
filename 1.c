#include <GL/freeglut.h>
#include <GL/gl.h>
#include<math.h>
#include<stdio.h>
void DDA_Line(int x1,int y1,int x2,int y2 );
void plot(int x,int y);
void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
    
    DDA_Line(0,240,320,0);
    DDA_Line(320,0,640,240);
    DDA_Line(640,240,320,480);
    DDA_Line(0,240,320,480);
    
    DDA_Line(0,0,640,0);
    DDA_Line(0,0,0,480);
    DDA_Line(0,479,639,479);
    DDA_Line(639,0,639,480);
    
    DDA_Line(160,120,160,360);
    DDA_Line(160,360,480,360);
    DDA_Line(480,360,480,120);
    DDA_Line(480,120,160,120);
    glFlush();
}
void DDA_Line(int x1,int y1,int x2,int y2 )
{
	int dx,dy,mod_dx,mod_dy;
	float Xinc,Yinc,X,Y,steps;
	dx=x2-x1;
	dy=y2-y1;
	if(dx<0)
	{
		mod_dx=-dx;
	}
	else
	{
		mod_dx=dx;
	}
	if(dy<0)
	{
		mod_dy=-dy;
	}
	else
	{
		mod_dy=dy;
	}
	
	if(mod_dx > mod_dy)
	{
		steps=mod_dx;
	}
	else
	{
		steps=mod_dy;
	}
	
	Xinc=dx/steps;
	Yinc=dy/steps;
	X=x1;
	Y=y1;
	plot(round(X),round(Y));
	for(int i=0;i<steps;i++)
	{
		X=X+Xinc;
		Y=Y+Yinc;
		plot(round(X),round(Y));
	}
	

}
void plot(int x,int y)
{
	 glBegin(GL_POINTS);
        glVertex2i(x, y); 
    glEnd();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
