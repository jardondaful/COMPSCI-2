#include <iostream>
#include <fstream>
#include <string.h>
#include <set>
#include <iterator>
#include <typeinfo>
#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
  string filename;
  ifstream inFile("input.txt");
  unordered_map<string, int> word_set;  
  string word;
  while(inFile >> word)
  {
    ++word_set[word];
  }
  for (auto i = word_set.begin(); i != word_set.end(); i++)
  {
  cout <<"The word '"<< i->first <<"' appears "<< i->second <<" times in input.txt"<< endl;
  }
  return 0;
}



