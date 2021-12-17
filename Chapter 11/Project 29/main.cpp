#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string get_move(int n, int from, int to);

class DiskMover
{
  private:
    static const int a = 1;
    static const int b = 2;
    static const int c = 4;
    static const int d = 8;
    int n;
    int from;
    int to;
    int state;
    DiskMover *before;
    DiskMover *after;

  public:
    DiskMover(int n, int from, int to);
    ~DiskMover();
    string next_move()
    {
      if (state == DiskMover::a)
      {
        if (before != nullptr && before->has_more_moves())
        {
          string result = before->next_move();
          if (!before->has_more_moves())
          {
            state = DiskMover::b;
          }
        return result;
        }
        else
        {
      state = DiskMover::b;
        }
      }
      if (state == DiskMover::b)
      {
        if (after != nullptr && after->has_more_moves())
        {
          state = DiskMover::c;
        }
        else
        {
          state = DiskMover::d;
        }
        return get_move(n, from, to);
      }
      if (state == DiskMover::c)
      {
        string result = after->next_move();
        if (!after->has_more_moves())
        {
          state = DiskMover::d;
        }
      return result;
      }
      return "";
    }
    bool has_more_moves()
    {
        if (state != DiskMover::d)
        {
          return true;
        }
      return false;
    }
};

DiskMover::DiskMover(int n, int from, int to) : n{n}, from{from}, to{to}, state{DiskMover::a}
{
  if (n > 1)
  {
    int remaining_pole = 6 - from - to;
    before = new DiskMover{n - 1, from, remaining_pole};
    after = new DiskMover{n - 1, remaining_pole, to};
  }
  else
  {
    before = nullptr;
    after = nullptr;
  }
}

DiskMover::~DiskMover()
{
  delete before;
  delete after;
  before = nullptr;
  after = nullptr;
}


string get_move(int n, int from, int to)
{
  stringstream move;
  move << "Move disk " << n << " from peg " << from << " to peg " << to;
  return move.str();
}

int main()
{
  DiskMover mover(5, 1, 3);
  while (mover.has_more_moves())
  {
    cout << mover.next_move() << endl;
  }
  return 0;
}
