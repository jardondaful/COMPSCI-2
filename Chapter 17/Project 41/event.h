#ifndef EVENT_H
#define EVENT_H
#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
using std::priority_queue;
using std::vector;

inline int rand_int(int min, int max) 
{ 
  return rand() % (max-min) + min; 
} 

class Event
{
  public:
    Event(int t);
    virtual void do_event() = 0;
  protected:
    friend class EventComparison;
    int time;
};

class EventComparison
{
  public:
    bool operator()(const Event* left, const Event* right) const;
};

inline Event::Event(int t) : time(t) {}

inline bool EventComparison::operator() (const Event* left, const Event* right) const
{
  return left->time > right->time;
}

class Simulation
{
  public:
    void schedule_event(Event* new_event);
    void run();
  private:
    priority_queue<Event*, vector<Event*>, EventComparison> event_queue;
};

inline void Simulation::schedule_event(Event* new_event)
{
  event_queue.push(new_event);
}

#endif
