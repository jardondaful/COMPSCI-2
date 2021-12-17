#include <iostream>
using namespace std;
class Person
{
  private:
  string name;
  string friends;
  public:
  Person(){}
  Person(string aName)
  {
    name = aName;
    friends = "";
  }
  void befriend(Person p)
  {
     if(friends.length()==0)
     {
     friends = friends + p.name;
     }
     else
     {
     friends = friends + " " + p.name;
     }
  }
  void unfriend(Person p)
  {
    size_t pos = string::npos;
    while((pos=friends.find(p.name))!=string::npos)
    {
      friends.erase(pos,p.name.length());
    }  
  }
  string get_friend_names()
  {
    return friends;
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
  cout<<"Jake unfriended Scully because Scully ate his microwaved burrito"<<endl<<endl;
  a.unfriend(d);
  cout<<"Jake's current friends are now the following: "<<endl<<a.get_friend_names()<<endl;
  return 0;
}
