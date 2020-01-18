#include <GL/freeglut.h>
#include <GL/gl.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
float xc,yc,r;
void DDA_line(float,float,float,float);
void plot(int,int);
#define  pi 3.142857
void CREATE_CIRCLE_MID_POINT_ALGORITHM (int);
void renderFunction()
{	
    glClearColor(9.0, 6.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(3.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
    DDA_line(0.0,240.0,640.0,240.0);
    DDA_line(320.0,0.0,320.0,480.0);
 	 
    DDA_line((xc-((float)sqrt(3.0)*r)),(yc-r),(xc+((float)sqrt(3.0)*r)),(yc-r)); 
  	
  	DDA_line((xc+((float)sqrt(3.0)*r)),(yc-r),(xc+0),(yc+(2*r))); 
  	
	DDA_line((xc+0),(yc+(2*r)),(xc-((float)sqrt(3.0)*r)),(yc-r)); 
	   	
 CREATE_CIRCLE_MID_POINT_ALGORITHM(r);  	
  	
   	   	
 int R=(2*r);
 CREATE_CIRCLE_MID_POINT_ALGORITHM(R);  	
  	
	
  	glFlush();
     
}


void CREATE_CIRCLE_MID_POINT_ALGORITHM (int r) {

    int x=0,y=r;  //start from x=0,y=r.find po=1-r ,pk=x^2+y^2-r^2, x and y is midpt of competing cordinates
    int Po=1-r;  //for x=0,y=r po=1-r approx as midpt=y-.05,x=x+1
    int Pk=Po;
   
    while(x<=y)  //while x<y i,e above 45 degree line
    {  	if(Pk<0)     //if pk<0 means that midpoint is inside we plot x+1 and y
    	{	x=x+1;
    	    y=y;
  			plot(x+xc,y+yc);	
  			plot(-x+xc,y+yc); 
  			plot(-y+xc,x+yc); 
  			plot(-y+xc,-x+yc); 	    
    	    plot(-x+xc,-y+yc);
    	    plot(x+xc,-y+yc);
    	    plot(y+xc,-x+yc);
    	    plot(y+xc,x+yc); 
    		Pk=Pk+2*(x)+1;	//next value for pk is evaluated by (xk+1)^2+(yK)^2-r^2
    	}
    	
    	else if(Pk>0)   //if pk>0 then pt is outside circle we plot x+1 and y-1
    	{	x=x+1;
    	    y=y-1;
    	    plot(x+xc,y+yc);
  			plot(-x+xc,y+yc); 
  			plot(-y+xc,x+yc); 
  			plot(-y+xc,-x+yc);  	    
    	    plot(-x+xc,-y+yc);
    	    plot(x+xc,-y+yc);
    	    plot(y+xc,-x+yc);
    	    plot(y+xc,x+yc); 
    		Pk=Pk+(2*(x))+1-(2*(y));	//next value for ppk is calculated by (xk+1)^2+(yk-1)^2-r^2
       	}
     }
    
}


void DDA_line(float x1,float y1,float x2,float y2)
{	float x_increment,y_increment,diff_x,diff_y;
	float i;
	float steps=0.0;
	diff_x=x2-x1;
	diff_y=y2-y1;
	float m=(diff_y/diff_x);
	if(abs(diff_y)>=abs(diff_x))
	steps=abs(diff_y);
	else
	steps=abs(diff_x);
	x_increment=diff_x/steps;
	y_increment=diff_y/steps;
	plot(round(x1),round(y1));
	
	for(i=1;i<=steps;i++)
	{
		x1+=x_increment;
		y1+=y_increment;
		plot(round(x1),round(y1));
	}

}


void plot(int x, int y)
{	glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}



int main(int argc, char** argv)
{	

    printf("\n******* ENTER CO-ORDINATES OF CENTRE OF CIRCLE *******");
    printf("\nENTER X CO-ORDINATE: ");
    scanf("%f",&xc);
    printf("\nENTER Y CO-ORDINATE: ");
    scanf("%f",&yc);
    printf("\nENTER RADIUS OF IN-CIRCLE \'r\': ");
    scanf("%f",&r);
   
   

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0; 
}
