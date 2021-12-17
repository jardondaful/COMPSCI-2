#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

bool is_palindrome(string str) 
{
  if (str.length() <= 1)
  {
     return true;
  }
  char first_char = tolower(str[0]);
  char last_char = tolower(str[str.length() - 1]);
  if (!isalpha(first_char)) 
  {
    return is_palindrome(str.substr(1));
  } 
  else if (!isalpha(last_char)) 
  {
    return is_palindrome(str.substr(0, str.length() - 1));
  } 
  else 
  {
    if (first_char == last_char) 
    {
      string shorter = str.substr(1, str.length() - 2);
      return is_palindrome(shorter);
    } 
    else 
    {
      return false;
    }
  }
}

int main() 
{
  cout << "Enter a string to see wheter or not it is a palindrome: ";
  string input;
  getline(cin, input);
  cout << "\n"<< input << " is ";
  if (!is_palindrome(input)) 
  {
   cout << "not ";
  }
  cout << "a palindrome." << endl;
  return 0;
}
