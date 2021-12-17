#include <iostream> 
using namespace std; 

int get_max(int arr[], int n) 
{ 
  int mx = arr[0]; 
  for (int i = 1; i < n; i++) 
  {
    if (arr[i] > mx) 
    {
      mx = arr[i]; 
    }
  }
  return mx; 
} 
 
void count_sort(int arr[], int n, int exp) 
{ 
  int output[n];
  int i, count[10] = { 0 }; 
  for (i = 0; i < n; i++) 
  {
    count[(arr[i] / exp) % 10]++; 
  }
  for (i = 1; i < 10; i++) 
  {
    count[i] += count[i - 1]; 
  }
  for (i = n - 1; i >= 0; i--) 
  { 
    output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
    count[(arr[i] / exp) % 10]--; 
    } 
  for (i = 0; i < n; i++) 
  {
    arr[i] = output[i]; 
  }
} 

void radix_sort(int arr[], int n) 
{ 
  int m = get_max(arr, n);  
  for (int exp = 1; m / exp > 0; exp *= 10) 
  {
    count_sort(arr, n, exp); 
  }
} 

void print(int arr[], int n) 
{ 
  for (int i = 0; i < n; i++) 
  {
    cout << arr[i] << " "; 
  }
} 

int main() 
{ 
  int arr[] = {156, 46, 79, 900, 500, 36, 0,999,1,2,99}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  cout<<"These are the elements of an unsorted array: "<<endl;
  print(arr,n);
  radix_sort(arr, n);
  cout<<endl<<endl;
  cout<<"These are the elements of the previous array but sorted: "<<endl;
  radix_sort(arr,n); 
  print(arr, n); 
  cout<<endl<<endl;
  int arr2[] = {699,505,40,387,998,999,0,1,4,58,677,394,500,99,87, 4}; 
  int n2 = sizeof(arr2) / sizeof(arr2[0]); 
  cout<<"These are the elements of an unsorted array: "<<endl;
  print(arr2,n2);
  radix_sort(arr2, n2);
  cout<<endl<<endl;
  cout<<"These are the elements of the previous array but sorted: "<<endl;
  radix_sort(arr2,n2); 
  print(arr2, n2); 
  return 0; 
}
