 #include<stdio.h>
 #include<iostream>
 #include<graphics.h>

 using namespace std;
 //////////////////function declarations//////////////////////////////
 float c[3][3];
 void reflectiony(int,float c[3][3]);
 void multiar(int,float b[3][3],float c[3][3],float a[3][3]);
 void dis(int,float a[3][3]);
 void reflectionx(int ,float c[3][3]);
 //////////////////////////////////////////////////////////////////////

 void reflectionx(int n,float c[][3])//function reflection about y-axis
 {
    int i,j;
    float b[3][3],a[3][3];
   
   for(i=0;i<3;i++)
	 { 
	   for(j=0;j<3;j++)
	    {
	      b[i][j]=0;
	    }

	}
	   b[0][0]=-1;
	   b[1][1]=1;
   	 b[2][2]=1;
	 
	 multiar(n,b,c,a);
   	 dis(n,a);
}
 /////////////////////////////////////////////////////////////////////////                                                              
 void reflectiony(int n,float c[][3])//function reflection about x-axis
 {
    int i,j;
    float b[3][3],a[3][3];
   
   for(i=0;i<3;i++)
	 { 
	   for(j=0;j<3;j++)
	    {
	      b[i][j]=0;
	    }

	}
	   b[0][0]=1;
	   b[1][1]=-1;
   	 b[2][2]=1;
	 
	 multiar(n,b,c,a);
   	 dis(n,a);
}
///////////////////////////////////////////////////////////////
void multiar(int n,float b[3][3],float c[3][3],float a[3][3])
{ 
  int i,j,k;
  for(i=0;i<n;i++)
   {
     for(j=0;j<3;j++)
    	 {
     	    a[i][j]=0;
	     }
 
   }
for(i=0;i<n;i++)
 {
  for(j=0;j<3;j++)
   {  
     for(k=0;k<3;k++)
     {
    	a[i][j]=a[i][j]+c[i][k]*b[k][j];
     }
   }
 }
}
//////////////////////////////////////////////////////////
void dis(int n,float a[3][3])
 {
   float maxx,maxy;
    maxx=getmaxx();
    maxy=getmaxy();
    maxx=maxx/2;
    maxy=maxy/2;
    
    int  i=0;
   
while(i<n-1)
    { 
	   setcolor(BLUE);
       line(maxx+a[i][0],maxy-a[i][1],maxx+a[i+1][0],maxy-a[i+1][1]);
       i++;
    }
    i=n-1;

    setcolor(BLUE);
    delay(20);
    line(maxx+a[i][0],maxy-a[i][1],maxx+a[0][0],maxy-a[0][1]);
    setcolor(15);

    //x-axis and y-axis
    setcolor(GREEN);
    delay(20);
    line(0,maxy,maxx*2,maxy);
     delay(20);
    line(maxx,0,maxx,maxy*2);
}

///////////////////////////////////////////////////////////////////
 int main()//main body
 {   
    int gd=DETECT,gm,n,ch;
    float i;
    n=3;
	  cout<<"enter the cordinates"<<endl;
 
     cout<<"x1:";cin>>c[0][0];
     cout<<"y1:";cin>>c[0][1];
     cout<<"x2:";cin>>c[0][2];
     cout<<"y2:";cin>>c[1][0];
     cout<<"x3:";cin>>c[1][1];
     cout<<"y3:";cin>>c[1][2];
    c[2][0]=c[2][1]=c[2][2]=1;
  int x2=c[0][2];
  int y2=c[1][0];
	   cout<<"enter your choise:\n"<<endl;
     cout<<"**************************"<<endl;
	   cout<<"1.Reflection about x-axis"<<endl;
     cout<<"2.Reflection about y-axis \n3.Exit"<<endl;
	   cin>>ch;
    
	  switch(ch)
	  {
	    case 1:
	            initgraph(&gd,&gm,NULL);
              setbkcolor(WHITE);
              cleardevice();
                 
		        dis(n,c);
		        reflectiony(n,c);
            break;

       case 2: initgraph(&gd,&gm,NULL);
            setbkcolor(WHITE);
             cleardevice();

             dis(n,c);      
             reflectionx(n,c);
             break;
        

       case 3:  return 0;
             

       default : cout<<"enter again\n"<<endl;
	   }
   
	      getch();
        return 0;
 }
//**********************************************************************************//