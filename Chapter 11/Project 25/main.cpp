//textfile is so big that when trying to check valid word combos by reading through the entire vector of strings consisting of words from words.txt to check if a substring of the number matches with a valid word from the vector the program doesn't show any output.
#include<vector>
#include<iostream>
#include<string>
#include <fstream>
using namespace std;
class Solution {
  private:
  vector<string> combos;
public:
Solution(){}
Solution(vector<string> c)
{
combos = c;
}
    void myLetterCombination(string digits, vector<string> &res, string nums[], int i, string s)
    {
      if(i == digits.length())
      {
        combos.push_back(s);
        return;
      }
      string val = nums[digits[i] - '0'];
      for(int j=0;j<val.length(); j++)
       myLetterCombination(digits, res, nums, i+1, s+val[j]);
    } 
 
    vector<string> letterCombinations(string digits) 
    {
      if(digits.length() == 0)
        return combos;
      string nums[10] = 
      {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      myLetterCombination(digits, combos, nums, 0, "");
      return combos;
    }
};

int main()
{
  Solution a;
  string phone_number_prefix = "929";
  string phone_number_mid = "549";
  string phone_number_end = "2865";
  vector<string> b = a.letterCombinations(phone_number_prefix);
  vector<string> c = a.letterCombinations(phone_number_mid);
  vector<string> d = a.letterCombinations(phone_number_end);
  vector<string> e;
  cout<<"These are the valid word combinations of the phone number 9295492865: "<<endl<<endl;
  vector<string> words;
  ifstream file;
  file.open("words.txt");
  string word;
  while(file>>word)
  {
      words.push_back(word);
  }
  int aa = 0;
  for(int i = 0; i < words.size(); i++)
  {
    for(int j = 0; j < b.size(); j++)
    {
      if(b[j]==words[i])
      {
        e.push_back(words[i]);
      }
    }
  }
  aa = 0;
  for(int i = 0; i < words.size(); i++)
  {
    for(int j = 0; j < c.size(); j++)
    {
      if(c[j]==words[i])
      {
        e[aa] += " " + c[j];
        aa++;
      }
    }
  }
  aa = 0;
  for(int i = 0; i < words.size(); i++)
  {
    for(int j = 0; j < d.size(); j++)
    {
      if(d[j]==words[i])
      {
        e[aa] += " " + d[j];
        aa++;
      }
    }
  }
  for(int i = 0; i < e.size(); i++)
  {
    if(e[i].size()==12)
    {
      cout<<e[i]<<endl<<endl;
    }
  }
  return 0;
}



