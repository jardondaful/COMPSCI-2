#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;
class Appointment
{
  private:
  string description;
  string ti;
  int year;
  int month;
  int day;
  public:
  Appointment(){}
  Appointment(string de, string t, int y, int m, int da)
  {
    description = de;
    ti = t;
    year = y;
    month = m;
    day = da;
  }
  virtual void occurs_on(int y, int m, int d)
  {
    if(year-y==0&&month-m==0&&day-d==0)
    {
      cout<<description<<" at "<<ti<<" on"<<" "<<month<<"/"<<day<<"/"<<year<<endl;
    }
  }
};
class Onetime: public Appointment
{
  private:
  string description;
  string ti;
  int year;
  int month;
  int day;
  public:
  Onetime(){}
  Onetime(string de, string t, int y, int m, int da)
  {
    description = de;
    ti = t;
    year = y;
    month = m;
    day = da;
  }
   virtual void occurs_on(int y, int m, int d)
  {
    if(year-y==0&&month-m==0&&day-d==0)
    {
      cout<<description<<" at "<<ti<<" on"<<" "<<month<<"/"<<day<<"/"<<year<<endl;
    }
  }
};

class Daily: public Appointment
{
  private:
  string description;
  string ti;
  int year;
  int month;
  int day;
  public:
  Daily(){}
  Daily(string de, string t, int y, int m, int da)
  {
    description = de;
    ti = t;
    year = y;
    month = m;
    day = da;
  }
   virtual void occurs_on(int y, int m, int d)
  {
    cout<<description<<" at "<<ti<<" that has started since"<<" "<<month<<"/"<<day<<"/"<<year<<endl;
  }
};

class Weekly: public Appointment
{
  private:
  string description;
  string ti;
  int year;
  int month;
  int day;
  public:
  Weekly(){}
  Weekly(string de, string t, int y, int m, int da)
  {
    description = de;
    ti = t;
    year = y;
    month = m;
    day = da;
  }
    virtual void occurs_on(int y, int m, int d)
  {
    int da = d;
    bool a = false;
    while(a==false)
    {
   while (da<30)
   {
     if(da==day)
     {
       cout<<description<<" at "<<ti<<" that has started since "<<month<<"/"<<day<<"/"<<year<<endl;
       a=true;
       break;
     }
     da+=7;
   }
   da = da%30;
  }
  }
};

class Monthly: public Appointment
{
  public:
  string description;
  string ti;
  int year;
  int month;
  int day;
  Monthly(){}
  Monthly(string de, string t, int y, int m, int da)
  {
    description = de;
    ti = t;
    year = y;
    month = m;
    day = da;
  }
 virtual void occurs_on(int y, int m, int d)
  {
    if(day==d)
    {
      cout<<description<<" at "<<ti<<" that has started since"<<" "<<month<<"/"<<day<<"/"<<year<<endl;
    }
  }
};

int main() 
{
  vector<Appointment*> appointments;
  Appointment a = Appointment("Chipped tooth", "2:30 PM", 2020, 5, 10);
  appointments.push_back(new Monthly("Montly checkup", "5:30 PM", 2017, 3, 10));
  appointments.push_back(new Monthly("Montly psychiatrist appointment", "5:30 PM", 2017, 3, 9));
  appointments.push_back(new Onetime("Broken arm", "6:00 PM", 2020, 11, 11));
  appointments.push_back(new Onetime("Vaccine", "3:30 PM", 2020, 5, 10));
  appointments.push_back(new Weekly("Weekly chiropractor visit", "4:30 PM",2020, 5, 3));
  appointments.push_back(new Daily("Daily massage", "11:00 AM", 2019, 9, 8));
  cout<<"Here are the appointments that also occur on the same date as the chipped tooth appointment at 2:30 PM on 5/10/2020: "<<endl<<endl;
  for(int i = 0; i < appointments.size(); i++)
  {
    appointments[i]->occurs_on(2020, 5, 10);
  }
  return 0;
}
