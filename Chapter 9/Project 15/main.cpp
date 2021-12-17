#include <iostream>
#include <vector>
#include<sstream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
class Person
{
  private:
  string name;
  vector<Person*> friends;
  public:
  Person(){}
  Person(string aName)
  {
    name = aName;
    friends = {};
  }
  //changed parameter slightly to accomodate for vector of pointers
  void befriend(Person &p)
  {
    friends.push_back(new Person(p));
  }
  //changed parameter slightly to accomodate for vector of pointers
  void unfriend(Person &p)
  {
      string a = p.name;
      string* n;
      n = &a;
      stringstream ss;
      ss<<*n;
      string nn = ss.str();
      for(int i = 0; i < friends.size(); i++)
      {
        if(nn.compare(friends[i]->name)==0)
        {
          friends.erase(friends.begin()+i);
        }
      }
  }
  string get_friend_names()
  {
    string names_of_friends = "";
    for(int i = 0; i < friends.size(); i++)
    {
      string b = friends[i]->name;
      string* m;
      m = &b;
      stringstream ss;
      ss<<*m;
      string mm = ss.str();
      names_of_friends+=mm+" ";
    }
    return names_of_friends;
  }
};

int main()
{
  Person a;
  Person b;
  Person c;
  Person d;
  a = Person("Jake");
  b = Person("Amy");
  c = Person("Rosa");
  d = Person("Scully");
  a.befriend(b);
  a.befriend(c);
  a.befriend(d);
  cout<<"Jake befriended the following people at work: "<<endl<<a.get_friend_names()<<endl<<endl;
  cout<<"Jake is not friends with Scully anymore because Scully ate his microwaved burrito"<<endl<<endl;
  a.unfriend(d);
  cout<<"Jake's current friends are now the following: "<<endl<<a.get_friend_names()<<endl;
  return 0;

}
