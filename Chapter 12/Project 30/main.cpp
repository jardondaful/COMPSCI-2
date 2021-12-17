#include <bits/stdc++.h>
#include<ctime>
using namespace std;

int swap(int *a, int *b) 
{
    int t = *a;
    *a = *b;
    *b = t;
    return 0;
}

int pivIndex(int arr[], int l, int r)
{
  int x = arr[r], i = l;
  for (int j = l; j <= r - 1; j++) 
  {
    if (arr[j] <= x) 
    {
      swap(&arr[i], &arr[j]);
      i++;
    }
  }
  swap(&arr[i], &arr[r]);
  return i;
}

int select(int arr[], int k, int l, int r)
{
  if (k > 0 && k <= r - l + 1) 
  {
    int p = pivIndex(arr, l, r);
    if (p - l > k - 1)
    {
      return select(arr, k, l, p - 1);
    }
   else if(p - l < k - 1)
   {
    return select(arr, k - p + l - 1, p + 1, r);
   }
  return arr[p];
  }
return INT_MAX;
}

//nonrecursive method that sorts the elements before calculating the median
double findMedian(int a[], int n) 
{ 
    sort(a, a + n); 
    if (n % 2 != 0) 
    {
      return (double)a[n / 2]; 
    }
    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0; 
} 
void print(int a[], int size)
{  
   for (int i = 0; i < size; i++)
   {
      cout << a[i] << " ";
   }
   cout << endl;
}

int main()
{
  srand(time(0));
   const int size = 101;
   int values[size];
   for (int i = 0; i < size; i++)
   {
      values[i] = rand() % 100;
   }
   cout<<"The randomly generated elements: "<<endl;
   print(values, 101);
  int k = size/2+1;
  cout<<endl;
  cout << "The calculated median element using the recursive method is "<< select(values, k, 0, size - 1)<<endl;
  int before = time(0);
  select(values, k, 0, size - 1);
  int after = time(0);
  cout<<"The elapsed time for the recursive method is "<<after-before<<" seconds"<<endl;
  int before2 = time(0);
  findMedian(values, sizeof(values)/sizeof(values[0]));
  int after2 = time(0);
  cout<<"The calculated median element using the nonrecursive method is "<<findMedian(values, 101)<<endl;
  cout<<"Elapsed time for the non-recursive method is " <<after2-before2<< " seconds"<<endl<<endl;
  cout<<"The time difference between the recursive and nonrecursive method is "<<(after2-before2)-(after-before)<< " seconds";
  return 0;
}



