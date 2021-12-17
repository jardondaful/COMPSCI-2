#include <iostream>
#include <iomanip>
using namespace std;
const int rows = 10;
const int columns = 10;

struct Pair
{
   int row;
   int col;
   Pair(int r = 0, int c = 0)
   {
      row = r;
      col = c;
   }
};

class Stack
{
  private:
    Pair data[rows*columns];
    int top;
  public:
    Stack()
    {
      top = 0;
    }
    void push(Pair p)
    {
      data[top] = p;
      top++;
    }
    bool empty()
    {
      return top == 0;
    }
    Pair pop()
    {
      return data[--top];
    }
};

bool isColored(int pixels[rows][columns], Pair p)
{
  if(pixels[p.row][p.col] != 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isValid(Pair p)
{
  if(p.row >= 0 && p.row < rows && p.col >= 0 && p.col < columns)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
   Stack s;
   int pixels[rows][columns];
   for(int i = 0; i < rows; i++)
   {
     for(int j = 0; j < columns; j++)
     {
       pixels[i][j]=0;
     }
   }
   int row = 1;
   int col = 1;
   int count = 1;
   Pair p;
   cout << "Enter the index of the row you wish to start at (0-9): ";
   cin >> row;
   cout << "Enter the indx of the column you wish to start at (0-9): ";
   cin >> col;
   s.push(Pair(row, col));
   cout<<"\nThe 10x10 array of colors is represented as below: "<<endl<<endl;
   while(!s.empty())
   {
      p = s.pop();
      if(!isColored(pixels, p))
      {
        pixels[p.row][p.col] = count;
        count++;
      }
      Pair north(p.row-1, p.col);
      Pair east(p.row, p.col +1 );
      Pair south(p.row+1, p.col);
      Pair west(p.row, p.col-1);
      if(isValid(north) && !isColored(pixels, north))
      {
        s.push(north);
      }
      if(isValid(east) && !isColored(pixels, east))
      {
        s.push(east);
      }
      if(isValid(south) && !isColored(pixels, south))
      {
        s.push(south);
      }
      if(isValid(west) && !isColored(pixels, west))
      {
        s.push(west);
      }  
   }
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      cout << setw(5) << pixels[i][j];
    }
    cout << endl;
  }
  return 0;
}
