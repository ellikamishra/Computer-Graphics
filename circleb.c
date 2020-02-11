#include <GL/freeglut.h>
#include <GL/gl.h>
#include<math.h>
#include<stdio.h>
int R,X,Y;
void circle(int r,int xc,int yc);
void DDA_Line(float x1,float y1,float x2,float y2 );
void plot(int x,int y);
void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,640.0);
   /* for(int i=100;i<400;i=i+5)
    {
    	circle(R,i,320);
    }*/
   circle(R,X,Y);
    circle(R/2,X,Y);
    DDA_Line(X+0.866025*R,Y-0.5*R,X-0.866025*R,Y-0.5*R);
    DDA_Line(X-0.866025*R,Y-0.5*R,X,Y+R);
   DDA_Line(X+0.866025*R,Y-0.5*R,X,Y+R);
    glFlush();
}
void circle(int r,int xc,int yc)
{
	float D;
	int x,y;
	x=0;
	y=r;
	D=3-2*r;
	while(x<=y)
	{
		plot(x+xc,y+yc);
		plot(y+xc,x+yc);
		plot(y+xc,-x+yc);
		plot(x+xc,-y+yc);
		plot(-x+xc,-y+yc);
		plot(-y+xc,-x+yc);
		plot(-y+xc,x+yc);
		plot(-x+xc,y+yc);
		if(D<0)
		{
			D=D+4*x+6;
			x=x+1;
		}
		else
		{
			D=D+4*(x-y)+10;
			x=x+1;
			y=y-1;
		}
	}
}
void DDA_Line(float x1,float y1,float x2,float y2 )
{
	float dx,dy,mod_dx,mod_dy;
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
	for(float i=0;i<steps;i++)
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
    printf("Enter radius of outer circle :");
    scanf("%d",&R);
    printf("Enter X co ordinate of centre of circle :");
    scanf("%d",&X);
    printf("Enter Y co ordinate of centre of circle  :");
    scanf("%d",&Y);
    circle(R,X,Y);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
