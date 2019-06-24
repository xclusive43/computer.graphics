#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>

 using namespace std;

int main()
{
int graphdriver=DETECT,graphmode,errorcode;
int i,k,j,data;
int usr[2][3],pre[3][3] ;

int x2,y2,x1,y1,x,y;
printf("Enter the a point:");
printf("x1,y1 and x2,y2:");
cin>>usr[0][0]; cin>>usr[1][0]; cin>>usr[0][1];cin>>usr[1][2];
 

 
printf("sx,sy:");
scanf("%d%d",&x,&y);

initgraph(&graphdriver,&graphmode,NULL);

cleardevice(); 
 
//original line
line(usr[0][0],usr[1][0],usr[0][1],usr[1][2]);
 
pre[0][0]=pre[1][1]=pre[2][0]=pre[2][1]=pre[2][2]=1;

pre[0][0]=x;pre[1][1]=y;

usr[0][0]=usr[0][0]*pre[0][0];
usr[1][0]=usr[1][0]*pre[1][1];

usr[0][1]=usr[0][1]*pre[0][0];
usr[1][2]=usr[1][2]*pre[1][1]; 
 
//translate line
setcolor(GREEN);
line(usr[0][0],usr[1][0],usr[0][1],usr[1][2]);

getch();
closegraph();
return 0;
}
