#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
#include "event.h"
using namespace std;

void Simulation::run()
{
  while(!event_queue.empty()) 
  {
    Event* next_event = event_queue.top();
    event_queue.pop();
    next_event->do_event();
  }
}

class HotDogStand : public Simulation
{
  public:
    HotDogStand(){}
    HotDogStand(int f)
    {
      free_seats = f;
    }
    bool can_seat()
    {
      if (free_seats > 0) {
        free_seats--;
        return true;
    } else
        return false;
    }
    void customer_leaves()
    {
      free_seats++;
    }
  private:
    int free_seats;
};

HotDogStand chili_dog_stand(3);

class ArriveEvent : public Event
{
  public:
    ArriveEvent(int t);
    virtual void do_event();
};

class LeaveEvent : public Event
{
  public:
    LeaveEvent(int t);
    virtual void do_event();
};

ArriveEvent::ArriveEvent(int t) : Event(t) {}

void ArriveEvent::do_event()
{
  if (chili_dog_stand.can_seat()) 
  {
    cout << "Minute " << time << ": Customer is seated "<<endl;
    chili_dog_stand.schedule_event(new LeaveEvent(time + rand_int(1, 5)));
  }
  else
  {
      cout << "Minute " << time<< ": Customer is unable to find a seat, leaves "<<endl;
  }
}

LeaveEvent::LeaveEvent(int t) : Event(t) {}

void LeaveEvent::do_event()
{
    cout << "Minute " << time << ": Customer finishes eating, leaves "<<endl;
    chili_dog_stand.customer_leaves();
}

int main()
{
  cout<<"Simulation of a hot dog stand with 3 seats for one hour is as follows: "<<endl<<endl;
  for (int i = 0; i < 49; i++)
  {
    chili_dog_stand.schedule_event(new ArriveEvent(rand_int(1, 60)));
  }
  chili_dog_stand.run();
  return 0;
}
