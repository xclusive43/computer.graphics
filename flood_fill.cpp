#include<iostream>
#include<graphics.h>

using namespace std;

void floodfill(int x,int y,int color,int color1)
{
     
    if(getpixel(x,y)==color1 )
    {   delay(0.8);
        putpixel(x,y,color);
        floodfill(x+1,y,color,color1);
        floodfill(x-1,y,color,color1);
        floodfill(x,y+1,color,color1);
        floodfill(x,y-1,color,color1);
    }
}
int main()
{   int gd=DETECT,gm;
   

    int x,y,r;
    cout<<"enter the center point:"<<endl;cin>>x;cin>>y;
    cout<<"enter the area range:"<<endl;cin>>r;
    initgraph(&gd,&gm,NULL);

    cleardevice();

   setcolor(RED);
   arc(x,y,0,359,y-10);//0 to 360//x,y,start and end angle,radius//
   floodfill(x,y,9,0);
   
 
getch();
    return 0;
}