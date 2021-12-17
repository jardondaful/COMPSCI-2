#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;
class Battery
{
  private:
  double original_capacity;
  double remaining_capacity;
  public:
  Battery(){}
  Battery(double cap)
  {
    original_capacity = cap;
    remaining_capacity = cap;
  }
  void drain(double amount)
  {
    remaining_capacity= remaining_capacity-amount;
  }
  void charge()
  {
    remaining_capacity = original_capacity;
  }
  double get_remaining_capacity()
  {
    return remaining_capacity;
  }
};
int main()
{
  Battery a;
  a = Battery(2500.35);
  cout<<"Original capacity of double AA battery is "<<a.get_remaining_capacity()<<" mAh"<<endl<<endl;
  a.drain(500.32);
  cout<<"Capacity of double AA battery after last session of use is now "<<a.get_remaining_capacity()<< " mAh"<<endl<<endl;
  a.charge();
  cout<<"After recharging the battery, the capacity in the AA battery is now "<<a.get_remaining_capacity()<<" mAh"<<endl<<endl;
}
