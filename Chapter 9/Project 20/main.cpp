#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
class CashRegister
{
public:
  CashRegister(){}
  //modified constructor so it now takes in total sales before the day ended,total sales after the day ended, number of items sold before the day ended, and number of items sold after the day ended
  CashRegister(int i, double t, int ii, int tt)
  {
    items_sold = i;
    total_transacted = t;
    items_sold_after_today = ii;
    total_transacted_after_today = tt;
  }
   void clear()
   {
     total_transacted = 0.00;
     items_sold = 0;
   }
   void add_item(double price)
   {
     items_sold_after_today++;
     total_transacted_after_today+=price;
   }
   double get_total()
   {
     return total_transacted_after_today;
   }
   int get_count()
   {
     return items_sold_after_today;
   }
   void reset_sales()
   {
     total_transacted = total_transacted_after_today;
     items_sold = items_sold_after_today;
   }
   //interpreted the setting up of get_sales_total and get_sales_count ember functions as them returning values for a specific day since problem said that the store manager wanted to know how much business was transacted during the day
   double get_sales_total()
   {
     return total_transacted_after_today - total_transacted;
   }
  int get_sales_count()
  {
    return items_sold_after_today - items_sold;
  }
  
private:
  int items_sold;
  double total_transacted_after_today;
  double total_transacted;
  int items_sold_after_today;
};

int main()
{
  CashRegister a;
  int items_sold = 5;
  double total_sold = 20.00;
  int items_sold_after_today = items_sold;
  double total_sold_after_today = total_sold;
  a = CashRegister(items_sold, total_sold, items_sold_after_today, total_sold_after_today);
  a.add_item(5.36);
  a.add_item(9.98);
  a.add_item(3.35);
  a.add_item(4.45);
  cout<<"There were "<<a.get_count()<< " items processed by the cash register so far"<<endl<<endl;
  cout<<"The total price of the items scanned into the cash register is $"<<fixed<<setprecision(2)<<a.get_total()<<endl<<endl;
  cout<<"Total number of items scanned into this cash register today is "<<a.get_sales_count()<<endl<<endl;
  cout<<"Total amount of money that was processed from transactions today is $"<<a.get_sales_total()<<endl<<endl;
  a.reset_sales();
  cout<<"Everything is now updated and ready for more processing tomorrow!";
  a.clear();
 cout<<"Oh no! Now the cash register remembers nothing!!!";

}
