#include <iostream>
#include<time.h>
#include<cstdlib>
#include<ctime>
using namespace std;
struct Segment
{
  int indicator;
};
int y() {
    
  string arr[7][7] = {{"+","-","-","-","-","-", "+"},{"|", "X", "X", "X","X","X", "|"}, {"|","-","-","-","-","-", "|"}, {"|","|"," "," "," ","|", "|"}, {"|","-","-","-","-","-", "|"}, {"|", "X", "X", "X","X","X", "|"}, {"+","-","-","-","-","-", "+"}};
  for(int i = 0; i < 7; i++)
  {
    for(int j = 0; j < 7; j++)
    { 
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  Segment train1;
  train1.indicator = 1;
  Segment train2;
  train2.indicator = 1;
  Segment train3;
  train3.indicator = -1;
  Segment train4;
  train4.indicator = -1;
  int rand1 = 0;
  int rand2 = 0;
  int rand3 = 0;
  int rand4 = 0;
  int rand5 = 0;
  int rand6 = 0;
  int rand7 = 0;
  int rand8 = 0;
  while((rand1==0 && rand2==0 )||(rand1==0 && rand2==6 )||(rand1==6 && rand2==0) ||(rand1==6 && rand2==6) ||(rand1==1 && rand2==1) ||(rand1==1 && rand2==2 )||(rand1==1 && rand2==3) ||(rand1==1 && rand2==4 )||(rand1==1 && rand2==5) ||(rand1==3 && rand2==2) ||(rand1==3 && rand2==3) ||(rand1==3 && rand2==4) || (rand1==5 && rand2==1 )||(rand1==5 && rand2==2) ||(rand1==5 && rand2==3) ||(rand1==5 && rand2==4) ||(rand1==5 && rand2==5))
  {
  rand1 = rand()%7;
  rand2 = rand()%7;
  }
  while((rand1==0 && rand2==0 )||(rand1==0 && rand2==6 )||(rand1==6 && rand2==0) ||(rand1==6 && rand2==6) ||(rand1==1 && rand2==1) ||(rand1==1 && rand2==2 )||(rand1==1 && rand2==3) ||(rand1==1 && rand2==4 )||(rand1==1 && rand2==5) ||(rand1==3 && rand2==2) ||(rand1==3 && rand2==3) ||(rand1==3 && rand2==4) || (rand1==5 && rand2==1 )||(rand1==5 && rand2==2) ||(rand1==5 && rand2==3) ||(rand1==5 && rand2==4) ||(rand1==5 && rand2==5))
  {
  rand3 = rand()%7;
  rand4 = rand()%7;
  }
  while((rand1==0 && rand2==0 )||(rand1==0 && rand2==6 )||(rand1==6 && rand2==0) ||(rand1==6 && rand2==6) ||(rand1==1 && rand2==1) ||(rand1==1 && rand2==2 )||(rand1==1 && rand2==3) ||(rand1==1 && rand2==4 )||(rand1==1 && rand2==5) ||(rand1==3 && rand2==2) ||(rand1==3 && rand2==3) ||(rand1==3 && rand2==4) || (rand1==5 && rand2==1 )||(rand1==5 && rand2==2) ||(rand1==5 && rand2==3) ||(rand1==5 && rand2==4) ||(rand1==5 && rand2==5))
  {
  rand5 = rand()%7;
  rand6 = rand()%7;
  }
  while((rand1==0 && rand2==0 )||(rand1==0 && rand2==6 )||(rand1==6 && rand2==0) ||(rand1==6 && rand2==6) ||(rand1==1 && rand2==1) ||(rand1==1 && rand2==2 )||(rand1==1 && rand2==3) ||(rand1==1 && rand2==4 )||(rand1==1 && rand2==5) ||(rand1==3 && rand2==2) ||(rand1==3 && rand2==3) ||(rand1==3 && rand2==4) || (rand1==5 && rand2==1 )||(rand1==5 && rand2==2) ||(rand1==5 && rand2==3) ||(rand1==5 && rand2==4) ||(rand1==5 && rand2==5))
  {
  rand7 = rand()%7;
  rand8 = rand()%7;
  }
  if(rand2==0||(rand2==1&&rand1==3))
  {
    arr[rand1][rand2]="^";
  }
  else if(rand2==6||(rand2==5&&rand1==3))
  {
      arr[rand1][rand2]="v";
  }
 
 
  if(rand4==0||(rand4==1&&rand3==3))
  {
    arr[rand3][rand4]="^";
  }
  else if(rand4==6||(rand4==5&&rand3==3))
  {
      arr[rand3][rand4]="v";
  }
 
  if(rand6==0||(rand6==1&&rand5==3))
  {
    arr[rand5][rand6]="^";
  }
  else if(rand6==5||(rand6==6&&rand5==3))
  {
      arr[rand5][rand6]="v";
  }
 
  if(rand8==0||(rand8==1&&rand7==3))
  {
    arr[rand7][rand8]="^";
  }
  else if(rand8==5||(rand8==6&&rand7==3))
  {
      arr[rand7][rand8]="v";
  }
  
 if((rand2=!0&&rand1==0)||(rand2!=6&&rand1==2))
  {
    arr[rand1][rand2]=">";
  }
  else if((rand2!=0&&rand1==4)||(rand2!=6&&rand1==6))
  {
      arr[rand1][rand2]="<";
  }

  if((rand4=!0&&rand3==0)||(rand4!=6&&rand3==2))
  {
    arr[rand3][rand4]=">";
  }
  else if((rand4!=0&&rand3==4)||(rand4!=6&&rand3==6))
  {
      arr[rand3][rand4]="<";
  }
 
  if((rand6=!0&&rand5==0)||(rand6!=6&&rand5==2))
  {
    arr[rand5][rand6]=">";
  }
  else if((rand6!=0&&rand5==4)||(rand6!=6&&rand5==6))
  {
      arr[rand5][rand6]="<";
  }
 
  if((rand8=!0&&rand7==0)||(rand8!=6&&rand7==2))
  {
    arr[rand7][rand8]=">";
  }
  else if((rand8!=0&&rand7==4)||(rand8!=6&&rand7==6))
  {
      arr[rand7][rand8]="<";
  }

  for(int i = 0; i < 7; i++)
  {
    for(int j = 0; j < 7; j++)
    { 
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  return 0;
}

int main()
{
    srand((time(NULL)));
    string arr[7][7] = {{"+","-","-","-",">","-", "+"},{"|", "X", "X", "X","X","X", "|"}, {"|","-","-","-","<","-", "|"}, {"|","|"," "," "," ","|", "|"}, {"|","-","-",">","-","<", "|"}, {"|", "X", "X", "X","X","X", "|"}, {"+","-","-","-","-","-", "+"}};
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        cout<<endl;
    }
    for(int k = 0; k < 50; k++)
    {
    y();
    }
    return 0;
}
