//press run and then view the textfile. You will see the frequenciens in there
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h> 
using namespace std;

int main() {
  string encrypted_string;
  ifstream in_file;
  in_file.open("encrypted.txt");
  getline(in_file, encrypted_string);
  int a = 0;
  char str[encrypted_string.length()+1];
  strcpy(str, encrypted_string.c_str());
  int i = 0, alphabet[26]  = {0}, j;
   while (str[i] != '\0') {
      if (tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z') 
      {
         j = str[i] - 'a';
         ++alphabet[j];
      }
      ++i;
   }
     cout<<"Frequency of all alphabets in the string is:"<<endl;
   for (i = 0; i < 26; i++)
   {
     double l = alphabet[i];
     double len = encrypted_string.length();
     double p = l/len;
     string percent = to_string(p*100)+ "%";
     ofstream fileOUT("encrypted.txt", ios::app);
     fileOUT<<char(i + 'a')<< ": "<< percent<<endl;
     fileOUT.close();
   }
   cout<<"Check encrypted.txt.";
   return 0;
}
