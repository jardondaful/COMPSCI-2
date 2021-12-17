#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class PermutationIterator
{
  private:
  string s;
  int c;
  int i;
  vector<string> v;
  public:
  PermutationIterator(){}
  PermutationIterator(string w)
  {
    s = w;
    v = {};
    c = 0;
  }
  string next_permutation()
  {
    int n = s.length();
    int p[n];
    for(int i = 0; i < n; i++)
    {
      p[i] = 0;
    }
    int i = 1;
    int j = 0;
    v.push_back(s);
    while(i<n)
    {
      if(p[i]<i)
      {
        j = (i%2)*p[i];
        swap(s[j],s[i]);
        v.push_back(s);
        p[i]++;
        i=1;
      }
      else
      {
        p[i] = 0;
        i++;
    }
    }
    string a = v[c];
    c++;
    return a;
  }
  bool has_more_permutations()
  {
    int factorial = 1;
    for(int i = 1; i<=s.length(); i++)
    {
      factorial*=i;
    }
    if(c==factorial)
    {
      return false;
    }
    return true;
}
};

int main()
{
   PermutationIterator iter("arm");
  while(iter.has_more_permutations())
  {
     cout<<iter.next_permutation()<<endl;
  }
   return 0;
}
