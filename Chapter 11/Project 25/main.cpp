//This program lists all valid word sequences that spell the number on a phone pad.

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <algorithm>
using namespace std;

vector <string> dictionary;
 
vector<string> uploadDictionary(string infile)
{
  ifstream scan ( infile);
  if (!scan) return dictionary;
  string word;
  while (scan >> word) {
        for (char &c : word) c = toupper(c);  
        dictionary.push_back(word);
     }
  return dictionary;
}
 
bool vowel(string str)
{
  return str == "A" || str == "I" || str == "O";
}
 
bool contains (const vector<string> &d, string word)
{
  vector<string>::const_iterator it;
  for (it = d.begin(); it != d.end() && *it != word;  it++);
  return it != d.end();
}
ostream & operator<< (ostream & os, const vector<string>& words) 
{
  cout << "[";
  if ( words.size() > 0) 
  {
    cout << words[0] ;
    for (int i = 1; i < words.size(); i++)
    {
        cout << ", " << words[i] ;
    }
  }
  cout << "]";
  return os;
}

void print_words(string pin, vector<string> words)
{
  if (pin.length() == 0)
  {
    bool multiword = true;
    for (int j = 0; j < words.size() && multiword; j++)
    {
      string word = words[j];
      if (! contains(dictionary, word))
      {
        multiword = false;
      }
      if (word.length() == 1 && !vowel(word))
      {
        multiword = false;
      }
     }
    if (multiword)
    {
      cout << words[0];
      for (int j = 1; j < words.size(); j++)
      {
        cout << " " << words[j];
      }
      cout << endl;
     }
  }
  else
  {
    if (! words.empty() && contains(dictionary, words.back()) && (  words.back().length() > 1 || vowel(words.back())))
    {
      vector<string> wordCopy = words;
      wordCopy.push_back("");
      print_words(pin, wordCopy);
    }
    string map[] = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
     char currentDigit = pin[0];
     if (isdigit(currentDigit)) 
     {
      string letters = map[currentDigit - '0'];
      int i;
      for (i = 0; i < letters.size(); i++)
      {
        vector<string> wordCopy = words;
        if (wordCopy.empty())
        {
          wordCopy.push_back("");
        }
        string word = wordCopy.back() +letters[i];
        wordCopy.pop_back();
        wordCopy.push_back(word);
        print_words(pin.substr(1), wordCopy);
        }
     }
     else
     {
      vector<string> wordCopy = words;
      if (wordCopy.empty())
      {
        wordCopy.push_back("");
      }
      print_words(pin.substr(1), wordCopy);
     }
  }
}
 
void print_words(string n)
{
  vector <string> words;
  print_words(n, words );
}
 
int main ()
{
  uploadDictionary("words.txt");
  cout << "Enter a phone number: ";
  string num;
  cin >> num;
  cout<<endl;
  cout << "The valid keypad encodings for " << num << " are" << endl<<endl;
  print_words(num);
}

