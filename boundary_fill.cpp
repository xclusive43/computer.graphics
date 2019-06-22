#include<iostream>
#include<graphics.h>

using namespace std;

void boundary(int x,int y,int fillc,int boundarc)
{
     
    if(getpixel(x,y)!=boundarc && getpixel(x,y)!= fillc)
    {
        putpixel(x,y,fillc);
        boundary(x+1,y,fillc,boundarc);
        boundary(x,y+1,fillc,boundarc);
        boundary(x-1,y,fillc,boundarc);
        boundary(x,y-1,fillc,boundarc);
    }
}
int main()
{   int gd=DETECT,gm;
   

    int x,y,r;
    cout<<"enter the center point:"<<endl;cin>>x;cin>>y;cout<<"enter the area range:"<<endl;cin>>r;
    initgraph(&gd,&gm,NULL);
    cleardevice();
    circle(x,y,r);
    boundary(x,y,4,15);
    delay(10000000);

    
    closegraph();
    getch();
    return 0;
}