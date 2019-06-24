
//programme to Rotate a given triangle at theta degree
 #include<stdio.h>
 
 #include<graphics.h>
 #include<math.h>

void rotate(float[][3] ,float );
void mul(float[][3] ,float[][3] ,float[][3] );
void display(float[][3] );

void rotate(float c[][3],float r)
{
	int i,j;
	float b[10][3],xp,yp,rot[10][3],ang;
	xp=c[0][0];
	yp=c[0][1];

		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
			b[i][j]=0;//assigning matrix b to 0

		ang=r*3.14/180;
//set value to rotation matrix where
		b[0][0]=cos(ang);
		b[0][1]=sin(ang);
		b[1][0]=-sin(ang);
		b[1][1]=cos(ang);
		b[2][0]=(-xp*cos(ang))+(yp*sin(ang))+xp;//translation
		b[2][1]=(-xp*sin(ang))-(yp*cos(ang))+yp;//back translation
		b[2][2]=1;

	mul(b,c,rot);//multiply a matrix
	setcolor(BLUE);
	display(rot);
}
 
void rotateanti(float c[][3],float r)
{
	int i,j;
	float b[10][3],xp,yp,rot[10][3],ang;
	xp=c[0][0];
	yp=c[0][1];
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
			b[i][j]=0;//assigning matrix b to 0

		ang=r*3.14/180;

		//set value to rotation matrix where
		b[0][0]=cos(ang);
		b[0][1]=-sin(ang);
		b[1][0]=sin(ang);
		b[1][1]=cos(ang);
		b[2][0]=(-xp*cos(ang))+(-yp*sin(ang))+xp;//translation
		b[2][1]=( xp*sin(ang))-(yp*cos(ang))+yp;//back translation
		b[2][2]=1;

	mul(b,c,rot);//multiply a matrix
	setcolor(BLUE);
	display(rot);
}

void mul(float b[3][3],float c[3][3],float rot[3][3])
{
  int i,j,k;

	  for(i=0;i<3;i++)
	     for(j=0;j<3;j++)
		    rot[i][j]=0;

	for(i=0;i<3;i++)
	  for(j=0;j<3;j++)
	     for(k=0;k<3;k++)
			rot[i][j]=rot[i][j]+c[i][k]*b[k][j];

}
void display(float rot[3][3])
 {  
 
	line(rot[0][0],rot[0][1],rot[1][0],rot[1][1]);
	line(rot[1][0],rot[1][1],rot[2][0],rot[2][1]);
	line(rot[2][0],rot[2][1],rot[0][0],rot[0][1]);
}
 int main()
 {
	int gd=DETECT,gm,i,r;
	float c[3][3];
	
	
	printf("Enter three co-ordinates of a triangle:");
	 for(i=0;i<3;i++)
	  {
	    scanf("%f%f",&c[i][0],&c[i][1]);
	    c[i][2]=1;
	  }
	
	 int x;
	printf("press 1 for clockwise\t2.anti-clockwise:-");
	scanf("%d",&x);
	 switch(x)
	 {

		 case 1: 	printf("enter the angle of rotation:");
	            scanf("%d",&r);
						   initgraph(&gd,&gm,NULL);
								cleardevice();
								setcolor(RED);
								display(c);	//original triangle
		
	  				rotate(c,r);
						break;

		 case 2: 	printf("enter the angle of rotation:");
	 					    scanf("%d",&r);
								initgraph(&gd,&gm,NULL);
								cleardevice();
								setcolor(RED);
								display(c);	//original triangle
		
	  				rotateanti(c,r);
						break;

			default: printf("error!");
	 }
		

	   getch();
	  return 0;
 }
