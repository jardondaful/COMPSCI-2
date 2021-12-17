//current time reads to be seven hours ahead of actual time regardless of following code given from textbook. I have only overridden the get_hours() function
#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;
class Clock
{
  public:
   virtual int get_minutes()
  {
    time_t current_time = time(0);
    tm* local_time = localtime(&current_time);
    return local_time->tm_min;

  }
  virtual int get_hours()
{
  time_t current_time = time(0);
  tm* local_time = localtime(&current_time);
  return local_time-> tm_hour;
}
virtual string get_time()
{
  int hours = get_hours();
  int minutes = get_minutes();
  if(hours>12)
  {
    stringstream ss;
    ss<<(hours%12)<<":"<<minutes;
    string time;
    ss>>time;
    return time + " PM";
  }
  else
  {
    stringstream ss;
    ss<<(hours)<<":"<<minutes;
    string time;
    ss>>time;
    return time + " AM";
  }
}
};
class WorldClock: public Clock
{
  private:
    int ahead;
  public:
  WorldClock(){}
    WorldClock(int a)
    {
      ahead = a;
    }
   virtual int get_hours()
{
 time_t current_time = time(0);
  tm* local_time = localtime(&current_time);
  int hours = local_time->tm_hour;
  hours = hours + ahead;
  return hours;
}
};

int main() 
{
  Clock clock;
  cout<<"Current time: "<<clock.get_time()<<endl;
  WorldClock worldClock(3);
  cout<<"Time of three time zones ahead: "<<worldClock.get_time()<<endl;
  WorldClock m(7);
  cout<<"Time of seven time zones ahead: "<<m.get_time()<<endl;
  return 0;
}
