#include<iostream>
#include<vector>
using namespace std;
class CashRegister
{
public:
  CashRegister(){}
  CashRegister(vector<double> v)
  {
    vector = v;
  }
   void clear()
   {
     vector.clear();
   }
   void add_item(double price)
   {
     vector.push_back(price);
   }
   double get_total()
   {
     double total = 0;
     for(int i = 0; i < vector.size(); i++)
     {
       total+=vector[i];
     }
     return total;
   }
   int get_count()
   {
     return vector.size();
   }
   void display_all()
   {
     for(int i = 0; i < vector.size(); i++)
     {
       cout<<"$"<<vector[i]<<endl;
     }
   }
private:
  vector<double> vector;
};

int main()
{
  CashRegister a;
  vector<double> items = {};
  a = CashRegister(items);
  a.add_item(5.36);
  a.add_item(9.98);
  a.add_item(3.35);
  a.add_item(4.45);
  cout<<"Thre are "<<a.get_count()<< " items currently being processed by the cash register right now"<<endl<<endl;
  cout<<"The prices of the items scanned into the cash register are the following: "<<endl;
  a.display_all();
  cout<<endl;
  cout<<"The total price of the items scanned into the cash register is $"<<a.get_total()<<endl<<endl;
  a.clear();
  cout<<"After clearing the register, the items still in the cash register are the following: "<<endl<<endl;
  a.display_all();
  cout<<"Since there are no more items from the previous purchase being processed by the register, the next customer can come up!";
  return 0;
}
