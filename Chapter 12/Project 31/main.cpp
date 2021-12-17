#include <bits/stdc++.h>
#include<ctime>

using namespace std;

/**
   Swaps two integers.
   @param x the first integer to swap
   @param y the second integer to swap
*/
void swap(int& x, int& y)
{  
   int temp = x;
   x = y;
   y = temp;
}

/**
   Partitions a portion of an array.
   @param a the array to partition
   @param from the first index of the portion to be partitioned
   @param to the last index of the portion to be partitioned
   @return the last index of the first partition
*/
double findMedian(int a[], int n) 
{ 
    sort(a, a + n); 
    if (n % 2 != 0) 
    {
      return (double)a[n / 2]; 
    }
    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0; 
} 

int modified_partition_method(int a[], int from, int to)
{
   int pivot;
   if(to-from<=7)
   {
     pivot = (to-from)/2;
   }
   if(to-from<=40)
   {
     pivot = findMedian(a, to-from);
   }
   else
   {
     pivot = a[4];
   }
   int i = from - 1;
   int j = to + 1;
   while (i < j)
   {
      i++; while (a[i] < pivot) { i++; }
      j--; while (a[j] > pivot) { j--; }
      if (i < j) { swap(a[i], a[j]); }
   }
   return j;
}
/**
   Sorts a portion of an array, using quick sort.
   @param a the array to sort
   @param from the first index of the portion to be sorted
   @param to the last index of the portion to be sorted
*/
int old_partition_method(int a[], int from, int to)
{
   int pivot = a[from];
   int i = from - 1;
   int j = to + 1;
   while (i < j)
   {
      i++; while (a[i] < pivot) { i++; }
      j--; while (a[j] > pivot) { j--; }
      if (i < j) { swap(a[i], a[j]); }
   }
   return j;
}

void old_quicksort(int a[], int from, int to)
{
   if (from >= to) { return; }
   int p = old_partition_method(a, from, to);
   old_quicksort(a, from, p);
   old_quicksort(a, p + 1, to);
} 

void modified_quicksort(int a[], int from, int to)
{
   if (from >= to) { return; }
   int p = modified_partition_method(a, from, to);
   modified_quicksort(a, from, p);
   modified_quicksort(a, p + 1, to);
} 
  

/** 
   Prints all elements in an array.
   @param a the array to print
   @param size the number of elements in a
*/
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
   const int SIZE = 101;
   int values[SIZE];
   for (int i = 0; i < SIZE; i++)
   {
      values[i] = 3;
   }
   values[50]=2;
   values[60]=5;
   values[73]=6;
   values[80]=7;
   cout<<"The first set of numbers are "<<endl;
   print(values, SIZE);
   cout<<"The sorted numbers are "<<endl;
   old_quicksort(values, 0, SIZE - 1);
   print(values, SIZE);
  int before = time(0);
  old_quicksort(values, 0, SIZE - 1);
  int after = time(0);
  cout<<"The elapsed time to sort the first set of numbers using the qucksort method with the old partitioning method is "<<after-before<<" seconds";
  int before2 = time(0);
  modified_quicksort(values, 0, SIZE - 1);
  int after2 = time(0);
  cout<<"The elapsed time to sort the numbers using the qucksort method with the modified partitioning method is "<<after2-before2<<" seconds";

   return 0;
}
