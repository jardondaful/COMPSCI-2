#include<iostream>
using namespace std;

void swap(char& a, char& b)
{
  char temp;
  temp = a;
  a = b;
  b = temp;
}

void permutation(string str,int i,int n)
{
  if (i == n)
  {
    cout << str << "\t";
  }
  else
  {
  for (int j = i; j < str.length(); j++)
    {
      swap(str[i],str[j]);
      permutation(str, i + 1, n);
      swap(str[i],str[j]);
    }
  }
}

int main()
{
  string s;
  cout << "Enter the string of choice: ";
  cin >> s;
  cout << endl << "The permutations of the given string are as following: " << endl;
  permutation(s, 0, s.length() - 1);
  cout << endl;
}
