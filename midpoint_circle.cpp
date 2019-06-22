#include<graphics.h>
#include<iostream>
using namespace std;

int main()
{


int g_mode,g_driver=DETECT;
int x,y,x_mid,y_mid,radius,p;


cout<<"enter the coordinates :"<<endl;
cout<<"x :";cin>>x_mid;
cout<<"y :";cin>>y_mid;
cout<<"\n now enter the radius :"<<endl;
cin>>radius;
 
initgraph(&g_driver,&g_mode,NULL);

x=0;
y=radius;
p=5/4-radius;
do
{
putpixel(x_mid+x,y_mid+y,WHITE);
putpixel(x_mid+y,y_mid+x,WHITE);
putpixel(x_mid-y,y_mid+x,WHITE);
putpixel(x_mid-x,y_mid+y,WHITE);
putpixel(x_mid-x,y_mid-y,WHITE);
putpixel(x_mid-y,y_mid-x,WHITE);
putpixel(x_mid+y,y_mid-x,WHITE);
putpixel(x_mid+x,y_mid-y,WHITE);

if(p<0) 
{
    p=p+(2*x)+3;
}
else
 {
    y=y-1;
    p=p+(2*x)-(2*y)+5;
}

x=x+1;

}while(y>x);

getch();
return 0;
}