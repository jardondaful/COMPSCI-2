#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string get_full_key(string pt, string k)
{
  if(k.size() >= pt.size())
  {
    return k;
  }

  else
  {
    int psize = pt.size()-k.size();
    int ksize = k.size(); 
    while(psize >= ksize)
    {
      k += k;
      psize -= ksize;
    } 
    k += k.substr(0, psize);
    return k;
  }
}

string get_encryption_string(string pt, string k)
{
  string ct = "";
  for(int i=0;i<pt.size();i++)
  {
    ct += (char) (((int)pt[i]-'A' + (int)k[i]-'A') % 26) + 'A';
  }
  return ct;
}

string get_decryption_string(string ct, string k)
{
  string pt = "";
  for(int i=0;i<ct.size();i++)
  {
    pt += (char) ((((int)ct[i]- 'A' - (k[i] -'A')) + 26) % 26) + 'A';
  }
  return pt;
}

int main()
{
  string plainText;
  cout<<"Enter the message you want encrypted: ";
  cin>>plainText;
  transform(plainText.begin(), plainText.end(), plainText.begin(), ::toupper);
  string encoded;
  cout<<"Enter the message you want decrypted: ";
  cin>>encoded;
  string key;
  transform(encoded.begin(), encoded.end(), encoded.begin(), ::toupper);
  cout<<"Enter the key:";
  cin>>key;
  cout<<endl;
  transform(key.begin(), key.end(), key.begin(), ::toupper);
  key = get_full_key(plainText, key);
  string ciphertext = get_encryption_string(plainText, key);
  cout<<" The original plaintext encrypted (in all capital letters): "<< ciphertext <<endl;
  plainText = get_decryption_string(ciphertext, key);
  cout<<" The encrypted message decrypted (in all capital letters): "<< plainText <<endl;
  return 0;
}
