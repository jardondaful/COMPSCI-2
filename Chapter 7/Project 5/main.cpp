    #include <iostream>
    #include<time.h>
    using namespace std;
    //makes blank array of size 10 for gather. In this project I use arrays of size 10 to gather data.
    int * new_array()
    {
      static int r[10]= {};
      return r;
    }
    int * gather()
    { 
      //this portion calls on new_array() to get a blank array to fill
      int *b;
      b = new_array();
      //this portion calls on new_array() to get a blank array to fill
      for(int j = 0; j < 50; j++)
      {
      for(int i = 0; i < 10; i++)
      {
        b[i] = rand()%101;
      }
      cout<<"Array of gathered data: [";
      for(int i = 0; i < 10; i++)
      {
        cout<<b[i];
        if(i!=9)
        {
          cout<<" ";
        }
      }
      cout<<"]"<<endl;
      return b;  
      }
    }
    //gets array made from gather()
    int * next_array()
    {
      int* g;
      g = gather();
      return g;
    }
    
    void process()
    {
    //this portion gets array to process made from gather() by calling on next_array
    for(int j = 0; j < 50; j++)
    {
      int* c;
      c = next_array();
    //this portion gets array to process made from gather() by calling on next_array
      int sum = 0;
      int max = c[0];
      int min = c[1];
      for(int i = 0; i < 10; i++)
      {
        if(c[i]>max)
        {
          max = c[i];
        }
      }
      for(int i = 0; i < 10; i++)
      {
        if(c[i]<min)
        {
          min = c[i];
        }
      }
      for(int i = 0; i < 10; i++)
      {
        sum+=c[i];
      }
      double average = (sum*1.00)/10;
      cout<<"Average: "<<average<<endl;
      cout<<"Minimum: "<<min<<endl;
      cout<<"Maximum: "<<max<<endl;
      cout<<endl;
    }
    }
    int main() {
      srand(time(NULL));
      cout<<"Calling on gather() function: "<<endl;
      gather();
      cout<<endl;
      cout<<"Calling on process() function: "<<endl;
      process();
      return 0;
    }
