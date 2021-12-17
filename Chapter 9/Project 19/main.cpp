#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
class CashRegister
{
public:
  CashRegister(){}
  CashRegister(int i, double t, double tr)
  {
    item_count = i;
    total_price = t;
    tax_rate = tr;
  }
   void clear()
   {
     total_price = 0.00;
     item_count = 0;
   }
   void add_item(double price)
   {
     item_count++;
     total_price+=price;
   }
   double get_total()
   {
     return total_price;
   }
   int get_count()
   {
     return item_count;
   }
  void add_taxable_item(double a)
  {
    taxable.push_back(a);
    item_count++;
    total_price+=a;
  }
  double get_total_tax()
  {
    double total = 0;
    for(int i = 0; i < taxable.size(); i++)
    {
      total+=taxable[i];
    }
    return total*tax_rate;
  }
private:
  double total_price;
  int item_count;
  double tax_rate;
  vector<double> taxable;
};

int main()
{
  CashRegister a;
  int items = 0;
  double total = 0;
  double tax_rate = 0.08;
  a = CashRegister(items, total, tax_rate);
  a.add_item(5.36);
  a.add_item(9.98);
  a.add_item(3.35);
  a.add_item(4.45);
  a.add_taxable_item(3.99);
  a.add_taxable_item(9.56);
  cout<<"There were "<<a.get_count()<< " items processed by the cash register for this purchase"<<endl<<endl;
  cout<<"The additional amount you have to pay due to tax from taxable items processed by cash register is $"<<fixed<<setprecision(2)<<a.get_total_tax()<<endl<<endl;
  cout<<"The total price of the items scanned into the cash register is $"<<fixed<<setprecision(2)<<a.get_total()+a.get_total_tax()<<endl<<endl;
  a.clear();
  cout<<"Since there are no more items from the previous purchase being processed by the register, the next customer can come up!";

}
