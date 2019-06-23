#include<stdio.h>
#include<graphics.h>
 
void circle1(int,int,int);//functaion declaration 
void drawcircle( int x0,int y0,int x,int y);//functaion declaration 

int main()
{
	int gdriver=DETECT, gmode, error, x, y, r;
	
	printf("Enter radius of circle: ");
	scanf("%d", &r);//initialize radius
	 

	printf("Enter co-ordinates of center(x and y): ");
	scanf("%d%d", &x, &y);//initialize center pixel
 
	initgraph(&gdriver, &gmode,NULL);//graph initialization

	circle1(x, y, r);//function call
    getchar();
	return 0;
}

 


void circle1(int x0, int y0, int radius)//function defination
{
    int x = 0;
    int y = radius;

    int d =(3-2)*radius;//initial decision parameter
    
	drawcircle(x0,y0,x,y);//function call
while (y>=x)
    {   
	   x++;//update next x

	   if(d>0)
	   {
          y--;
		  d=d+4*(x-y)+10;
	   }

	   else
	   d=d+4*x+6;
	   drawcircle(x0,y0,x,y);
	   delay(30);
 
    }
 
 line(x0+radius,y0,x0-radius,y0);

}

void drawcircle(int x0,int y0,int x,int y)//function defination
 {	
	setcolor(GREEN);
	 
	putpixel(x0 - x, y0 - y, 2);
	putpixel(x0 - y, y0 - x, 2);
	putpixel(x0 + y, y0 - x, 2);
	putpixel(x0 + x, y0 - y, 2);
    

 
	}