#include <iostream>
#include<fstream>
#include <iterator>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef unordered_multiset<string>::iterator multi;

void print_multi_set(unordered_multiset<string> words)
{
  multi start = words.begin();
  multi end = words.end();
  std::for_each<multi&>(start, end, [&words, &start] (const string& word)
  {
  auto wordRange = words.equal_range(word);
  int count = static_cast<int>(distance(wordRange.first, wordRange.second)); 
  cout << "The word '"<<word << "' appears " << count <<" times in input.txt"<< endl; 
  advance(start, count - 1); 
  });
}

int main()
{
  string word;
  ifstream infile;
  unordered_multiset<string> word_set;   
  infile.open("input.txt");  
  while(!infile.eof())
   {
      infile>>word; 
      word_set.insert(word);
   }
   print_multi_set(word_set);
  return 0;
}
