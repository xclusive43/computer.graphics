#include<stdio.h>
#include<graphics.h>
 
void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
 
	dx=x1-x0;//calculate dx
	dy=y1-y0;//calculate dy
 
	x=x0;//initialize
	y=y0;//initialize
 
	p=2*dy-dx;//initial decision parameter
 
	while(x<x1)
	{
		if(p>=0)
		{   
			delay(20);
		    putpixel(x,y,3);

			y=y+1;//increment next y
			p=p+2*(dy-dx);//if p>=0 calculate p=p+2*(dx-dy)
		}

		else
		{   
			delay(20);
		    putpixel(x,y,3);
			p=p+2*dy;//p<0 calculate p+2*dy
		}
		x=x+1;//increment next x
	}
}
 
int main()
{
	int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
	
 
	printf("Enter co-ordinates of first point: ");
	scanf("%d%d", &x0, &y0);
    printf("Enter co-ordinates of second point: ");
	scanf("%d%d", &x1, &y1);

	initgraph(&gdriver, &gmode, NULL);//graph initialization
	drawline(x0, y0, x1, y1);//function call
     
	getchar();
	return 0;
}
