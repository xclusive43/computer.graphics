#include <iostream>
#include<graphics.h>

using namespace std;

//////////////////function declarations//////////////////////////////
 float c[2][3];
  
 void multiar(float b[2][3],float c[2][3],float a[2][3]);
 void translationx(float c[2][3],float s,float l);
 ////////////////////////////////////////////////////////////////////

 void translationx(float c[2][3],float s, float l)//function reflection about y-axis
 {
    int i,j;
    float b[2][3], a[2][3];
   
   for(i=0;i<3;i++)
	 { 
	   for(j=0;j<2;j++)
	    {
	      b[i][j]=0;
	    }
		}
    b[0][2]=s;
	b[1][2]=l;

    b[0][0]=b[1][1]=b[2][2]=1;
	 
	 multiar(b,c,a);
   	 
}
  
///////////////////////////////////////////////////////////////
void multiar(float b[2][3],float c[2][3],float a[2][3])
{ 
  int i,j,k;
  for(i=0;i<3;i++)
   {
     for(j=0;j<2;j++)
    	 {
     	    a[i][j]=0;
	     }
 
   }
for(i=0;i<3;i++)
 {
  for(j=0;j<2;j++)
   {  
     for(k=0;k<3;k++)
     {
    	a[i][j]=a[i][j]+c[i][k]*b[k][j];
     }
   }
 }

line(a[0][0],a[1][0],a[0][1],a[1][1]);
  
}
 
 int main()//main body
 {   
    int gd=DETECT,gm,ch;
    float i,d,z;
     
	  cout<<"enter the cordinates of a line"<<endl;
 
     cout<<"x1:";cin>>c[0][0];
     cout<<"x2:";cin>>c[0][1];
     cout<<"y1:";cin>>c[1][0];
     cout<<"y2:";cin>>c[1][1];

	 cout<<"enter the value of tx:"<<endl;
    cin>>d;
    cout<<"ty:"<<endl;
	cin>>z;
     
    c[2][0]=c[2][1]=1;
  
	cout<<"enter your choise:\n"<<endl;
    cout<<"**************************"<<endl;
	cout<<"1.translation "<<endl;
     cout<<"2.Exit"<<endl;
	cin>>ch;
    
	  switch(ch)
	  {
	    case 1:
	            initgraph(&gd,&gm,NULL);
                //setbkcolor(WHITE);
                cleardevice();
                  setcolor(GREEN);

		         line(c[0][0],c[1][0],c[0][1],c[1][1]);
			     translationx(c,d,z);
		        break;


          case 2:  return 0; 
		 default : cout<<"enter again\n"<<endl;
	   }
           
	      getch();
        return 0;
 }
//**********************************************************************************//
