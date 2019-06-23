#include<stdio.h>
//#include<iostream>
#include<graphics.h>
#define ROUND(a) (a+0.5)
// using namespace std;
const int I=0;//inside 0000
const int L=1;//left   0001
const int R=2;//Right  0010
const int B=4;//Below  0100
const int A=8;//Above  1000
const int xmax=300;
const int ymax=300;
const int xmin=100;
const int ymin=100;
int gencode(double x,double y){
	int code = I;//0000 assume default
	if(x<xmin)
		code|=L;
	else if(x>xmax)
		code|=R;
	if(y<ymin)
		code|=B;
	else if(y>ymax)
		code|=A;
	return code;	
}

void cohensutherlandClip(double x1,double y1,double x2,double y2){
	int code1,code2,gd=DETECT,gm;
	code1=gencode(x1,y1);
	code2=gencode(x2,y2);
	int accept=0;
	initgraph(&gd,&gm,NULL);
	setcolor(WHITE);
	rectangle(xmin,ymin,xmax,ymax);
	outtextxy(x1-10,y1-20,"P");
	outtextxy(x2-10,y2-20,"Q");
	line(x1,y1,x2,y2);
	delay(500);
	while(1){
		if((code1==0)&&(code2==0))
			{ accept=1;break;}
		else if(code1 & code2){
			break;}
		else{
			int code_out;
			double x,y;
			if(code1!=0)
				code_out=code1;
			else 
				code_out=code2;
			//Line Intersection value with respect to a window		
			if(code_out & A)
				{ x=x1+(x2-x1)*(ymax-y1)/(y2-y1); y=ymax; }//intersection in xaxis with y=ymax
			else if(code_out & B)
				{ x=x1+(x2-x1)*(ymin-y1)/(y2-y1); y=ymin; }//intersection in xaxis with y=ymin
			else if(code_out & R)
				{ y=y1+(y2-y1)*(xmax-x1)/(x2-x1); x=xmax; }//intersection in xaxis with x=xmax
			else if(code_out & L)
				{ y=y1+(y2-y1)*(xmin-x1)/(x2-x1); x=xmin; }//intersection in xaxis with x=xmin
				//plotting a visible point from a line
			if(code_out==code1)
				{ x1=x; y1=y;
				  code1=gencode(x1,y1);}
			else
				{ x2=x;	y2=y;
				  code2=gencode(x2,y2); }
		}
	    }	
	if(accept)
		{
		//cleardevice();
		outtextxy(50,400,"Line is Visible with green color and point P' Q'");
		outtextxy(ROUND(x1)-10,ROUND(y1)-20,"P'");
		outtextxy(ROUND(x2)-10,ROUND(y2)-20,"Q'");
		setcolor(RED);
		line(ROUND(x1),ROUND(y1),ROUND(x2),ROUND(y2));
		}
	else
		/*cout<<"Line Rejected"<<endl;
	cout<<code1<<code2<<endl;*/
	outtextxy(50,400,"Line Completely outside of clipping Region");
	getch();
		closegraph();
}
int main(){
	double x1,y1,x2,y2;
	printf("Enter Line Coordinate :");
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	cohensutherlandClip(x1,y1,x2,y2);
return 0;
}






