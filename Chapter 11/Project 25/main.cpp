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
    void myLetterCombination(string digits, vector<string> &res, string nums[], int i, string s){
        if(i == digits.length()){
            combos.push_back(s);
            return;
        }
        string val = nums[digits[i] - '0'];
        for(int j=0;j<val.length(); j++)
            myLetterCombination(digits, res, nums, i+1, s+val[j]);
    } 
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return combos;
        string nums[10] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        myLetterCombination(digits, combos, nums, 0, "");
        return combos;
    }
};

int main()
{
Solution a;
string phone_number = "9295492865";
vector<string> b = a.letterCombinations(phone_number);
cout<<"These are the letter combinations of the number 9295492865: "<<endl<<endl;
vector<string> words;
ifstream file;
file.open("words.txt");
string word;
while(file>>word)
{
    words.push_back(word);
}
for(int i = 0; i < b.size(); i++)
{
  for(int j = 0; j < words.size(); j++)
    {
  if(b[i].substr(0,4).compare(words[j])==0)
  {
    cout<<words[j]<<" ";
  }
  if(b[i].substr(4,2).compare(words[j])==0)
  {
    cout<<words[j]<<" ";
  }
  if(b[i].substr(6,4).compare(words[j])==0)
  {
    cout<<words[j]<<endl;
  }
  if(b[i].substr(0,3).compare(words[j])==0)
  {
    cout<<words[j]<<" ";
  }
  if(b[i].substr(3,3).compare(words[j])==0)
  {
    cout<<words[j]<<" ";
  }
  if(b[i].substr(6,4).compare(words[j])==0)
  {
    cout<<words[j]<<endl;
  }
  if(b[i].substr(0,2).compare(words[j])==0)
  {
    cout<<words[j]<<" ";
  }
  if(b[i].substr(2,4).compare(words[j])==0)
  {
    cout<<words[j]<<" ";
  }
  if(b[i].substr(6,4).compare(words[j])==0)
  {
    cout<<words[j]<<endl;
  }
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
    void myLetterCombination(string digits, vector<string> &res, string nums[], int i, string s){
        if(i == digits.length()){
            combos.push_back(s);
            return;
        }
        string val = nums[digits[i] - '0'];
        for(int j=0;j<val.length(); j++)
            myLetterCombination(digits, res, nums, i+1, s+val[j]);
    } 
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return combos;
        string nums[10] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        myLetterCombination(digits, combos, nums, 0, "");
        return combos;
    }
};
int main()
{
Solution a;
string phone_number = "9295492865";
vector<string> b = a.letterCombinations(phone_number);
cout<<"These are the letter combinations of the number 9295492865: "<<endl<<endl;
vector<string> words;
ifstream file;
file.open("words.txt");
string word;
while(file>>word)
{
    words.push_back(word);
}
for(int i = 0; i < b.size(); i++)
{
  for(int j = 0; j < words.size(); j++)
    {
      //makes a phrase consisting of of a four letter word followed by a two letter word followed by a four letter word
  if(b[i].substr(0,4).compare(words[j])==0)
  {
    cout<<words[j]<<" ";
  }
  if(b[i].substr(4,2).compare(words[j])==0)
  {
    cout<<words[j]<<" ";
  }
  if(b[i].substr(6,4).compare(words[j])==0)
  {
    cout<<words[j]<<endl;
  }
  //makes a phrase consisting of a three letter word followed by a three letter word followed by a four letter word
  if(b[i].substr(0,3).compare(words[j])==0)
  {
    cout<<words[j]<<" ";
  }
  if(b[i].substr(3,3).compare(words[j])==0)
  {
    cout<<words[j]<<" ";
  }
  if(b[i].substr(6,4).compare(words[j])==0)
  {
    cout<<words[j]<<endl;
  }
  //makes one word
  if(b[i].compare(words[j])==0)
  {
    cout<<words[j]<<endl;
  }
}
}
return 0;
}





