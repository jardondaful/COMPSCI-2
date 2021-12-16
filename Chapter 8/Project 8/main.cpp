#include<bits/stdc++.h> 
#include<fstream>
using namespace std;  
string encoder(string key) 
{ 
  string encoded = ""; 
  bool arr[26] = {0}; 
  for (int i=0; i<key.size(); i++) 
  { 
    if(key[i] >= 'A' && key[i] <= 'Z') 
    { 
      if (arr[key[i]-65] == 0) 
      { 
        encoded += key[i]; 
        arr[key[i]-65] = 1; 
      } 
    } 
    else if (key[i] >= 'a' && key[i] <= 'z') 
    { 
      if (arr[key[i]-97] == 0) 
      { 
        encoded += key[i] - 32; 
        arr[key[i]-97] = 1; 
      } 
    } 
  } 
  for (int i=0; i<26; i++) 
  { 
    if(arr[i] == 0) 
    { 
      arr[i]=1; 
      encoded += char(91-i); 
      } 
  } 
  return encoded; 
} 

string decrypted_message(string msg, string encoded) 
{ 
  string cipher_string=""; 
  for (int i=0; i<msg.size(); i++) 
  { 
    if (msg[i] >='a' && msg[i] <='z') 
    { 
      int pos = msg[i]-97; 
      cipher_string += encoded[pos]; 
    } 
    else if (msg[i] >='A' && msg[i] <='Z') 
    { 
      int pos = msg[i]-65; 
      cipher_string += encoded[pos]; 
    } 
    else
    { 
      cipher_string += msg[i]; 
    } 
  } 
  return cipher_string; 
} 

int main() 
{  
  ifstream in_file;
  in_file.open("key.txt");
  string key; 
  getline(in_file, key);
  cout << "Keyword : " <<key << endl; 
  string encoded_string = encoder(key); 
  string message;
  cout<<"Please enter the message you want to be encrypted: ";
  cin>>message;
  cout << "Message before encryption : " << message << endl; 
  cout << "Encrypted text : " << decrypted_message(message,encoded_string) << endl; 
  return 0; 
} 
