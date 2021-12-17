//current time reads to be seven hours ahead of actual time when following code given from textbook. I have only overridden the get_hours() function
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
  string t = alarm(hours, minutes);
  string t1;
  if(hours>12)
  {
    stringstream ss;
    ss<<(hours%12)<<":"<<minutes;
    string time;
    ss>>time;
    t1 = time + " PM";
  }
  else
  {
    stringstream ss;
    ss<<(hours)<<":"<<minutes;
    string time;
    ss>>time;
    t1 = time + " AM";
  }
  string m;
  if(t.length()==5)
  {
    m = t.substr(3,2);
  }
  else
  {
    m = t.substr(2,2);
  }
  stringstream minutes2(m);
  int x = 0;
  minutes2>>x;
  string h;
  if(t.length()==5)
  {
    h = t.substr(0,2);
  }
  else
  {
    h = t.substr(0,1);
  }
  stringstream hours2(h);
  int y = 0;
  hours2>>y;
  string t2;
  if((x>=minutes&&y==hours)||y>=hours)
  {
    t2 = t1 + " Alarm";
  }
  else
  {
    t2 = t1;
  }
  return t2;
  }
virtual string alarm(int hours, int minutes)
  {
    stringstream ss;
    ss<<(hours)<<":"<<minutes;
    string time;
    ss>>time;
    return time;
  }
};
class WorldClock: public Clock
{
  private:
    int ahead;
    string al;
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
virtual string alarm(int hours, int minutes)
  {
    stringstream ss;
    ss<<(hours+ahead)<<":"<<minutes;
    string time;
    ss>>time;
    return time;
  }
};

int main() 
{
  Clock clock;
  string alarm1 = clock.alarm(2,59);
  cout<<"Alarm time: 2:59 AM"<<endl;
  cout<<"Current time (word 'alarm' attatched if time is past alarm time): "<<clock.get_time()<<endl;
  WorldClock w(3);
  cout<<"Time of three time zones ahead (word 'alarm' attatched if time is past alarm time): "<<w.get_time()<<endl;
  WorldClock m(7);
  cout<<"Time of seven time zones ahead (word 'alarm' attatched if time is past alarm time): "<<m.get_time()<<endl;
  return 0;
}
