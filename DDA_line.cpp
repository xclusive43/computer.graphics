#include <graphics.h>
#include <stdio.h>
#include<iostream>
#include <math.h>
using namespace std;
 
int main( )
{
	float x,y,x1,y1,x2,y2,dx,dy,step;
	int i,gd=DETECT,gm;
 
	cout<<"Enter the value of x1: "<<endl;
	cin>>x1; cout<<"y1:"<<endl; cin>>y1; cout<<"x2:"<<endl; cin>>x1; cout<<"y2:"<<endl; cin>>y1;
	 
	initgraph(&gd,&gm,NULL);

	dx=abs(x2-x1);
	dy=abs(y2-y1);
 
	if(dx>=dy)
		step=dx;
	else
		step=dy;
 
	dx=dx/step;
	dy=dy/step;
 
	x=x1;
	y=y1;
    
	i=1;
	while(i<=step)
	{
		putpixel(x,y,1);
		x=x+dx;
		y=y+dy;

		i=i+1;

		delay(25);
	}
     
	 getch();
     return 0;
}
