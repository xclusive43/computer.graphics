#include<iostream>
#include<graphics.h>

using namespace std;

void boundary(int x,int y,int fillc,int boundaryc)
{
     
    if(getpixel(x,y)!=boundaryc && getpixel(x,y)!= fillc)
    {
        putpixel(x,y,fillc);
        
        boundary(x-1,y,fillc,boundaryc);
        boundary(x,y-1,fillc,boundaryc);
        boundary(x,y+1,fillc,boundaryc);
        boundary(x+1,y,fillc,boundaryc);
       
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