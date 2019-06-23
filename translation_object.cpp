// C++ program for translation 
// of a single coordinate 
#include<iostream> 
#include<graphics.h> 
  
using namespace std; 
  
// function to translate point 
void translatePoint () 
{ 
    /* init graph and putpixel are used for  
       representing coordinates through graphical  
       functions  
    */
    int P[2][2],n;
    
    cout<<"enter the line coordinates"<<endl;
    for(int i=0;i<2;i++)
    {
    for(int j=0;j<2;j++);
    {  cin>>n;
         P[i][j]= n;  
    }
    }// coordinates of point 

    int T[2][2] = {20, 10};


    int gd = DETECT, gm, errorcode; 
    initgraph (&gd, &gm,  NULL);  
      
    cout<<"Original Coordinates p1 and p2 :"<<P[0][0]<<","<<P[1][0]<<"and"<<P[1][0]<<','<<P[1][1]; 
    Setcolor(RED);
    line(P[0][0],P[1][0], P[0][1],P[1][1]);
  
    // calculating translated coordinates 
    P[0][0] = P[0][0] + T[0]; 
    P[1][0] = P[1][0] + T[1]; 
    P[0][1] = P[0][1] + T[1];
    P[1][1] = P[1][1] + T[1];
    cout<<"\nTranslated Coordinates :"<< P[0]<<","<< P[1]; 
     
    // Draw new coordinatses 
    Setcolor(WHITE);
    line(P[0][0],P[1][0], P[0][1],P[1][1]); 
    
} 
  
// driver program 
int main() 
{   
     // translation factor 
    translatePoint (); 
           
            getch();
    return 0; 
}  