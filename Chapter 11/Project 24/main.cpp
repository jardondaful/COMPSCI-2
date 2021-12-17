#include<vector>
#include<iostream>
#include<string>
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
    void myLetterCombination(string digits, vector<string> &combinations, string nums[], int i, string s){
        if(i == digits.length())
        {
          combos.push_back(s);
          return;
        }
        string val = nums[digits[i] - '0'];
        for(int j=0;j<val.length(); j++)
        {
          myLetterCombination(digits, combos, nums, i+1, s+val[j]);
        }
    } 
  vector<string> letterCombinations(string digits) 
  {
    if(digits.length() == 0)
    {
      return combos;
    }
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
vector<string> b = a.letterCombinations("2345");
cout<<"These are the letter combinations of the number 2345: "<<endl<<endl;
for(int i = 0; i < b.size(); i++)
{
  cout<<b[i]<<endl;
}
}



