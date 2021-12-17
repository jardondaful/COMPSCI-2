#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class CashRegister
{
public:
  CashRegister(){}
  CashRegister(int i, double t)
  {
    item_count = i;
    total_price = t;
  }
   void clear()
   {
     total_price = 0;
     item_count = 0;
   }
   //converted the parameter entered (which is a double) into a string, removed the decimal from the string, and then converted the updated string into an integer that will be stored into the vector in the private declaration
   void add_item(double price)
   {
     string s =  to_string(price);
     s.erase(remove(s.begin(), s.end(), '.'), s.end());
     int i = stoi(s);
     item_count++;
    total_price+=i;
   }
   double get_total()
   {
     return 1.0*total_price/1000000.0;
   }
   int get_count()
   {
     return item_count;
   }
private:
//changed total_price from double to int to fit needs of project
  int item_count;
  int total_price;
};

int main()
{
  CashRegister a;
  int items = 0;
  double total_price = 0;
  a = CashRegister(items, total_price);
  a.add_item(5.36);
  a.add_item(9.98);
  a.add_item(3.35);
  a.add_item(4.45);
  cout<<"Thre are "<<a.get_count()<< " items currently being processed by the cash register right now"<<endl<<endl;
  cout<<"The total price of the items scanned into the cash register is $"<<a.get_total()<<endl<<endl;
  a.clear();
  cout<<"Since there are no more items from the previous purchase being processed by the register, the next customer can come up!";
}
