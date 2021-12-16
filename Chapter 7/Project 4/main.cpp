#include <iostream>
using namespace std;
#include<vector>
struct Course;
struct Student
{
  string name;
  vector<Course*> courses;
};
struct Course
{
  string name;
  vector<Student*> students;
};
void print_student(Student* s)
{
  cout<< s->name<<" is enrolled in the following classes: "<<endl;
 for(int i = 0; i < s->courses.size(); i++)
 {
   cout<<s->courses[i]->name<<endl;
 }
  cout<<""<<endl;
}
void print_course(Course* c)
{
  cout<<"Students that are enrolled in "<<c->name<< " are: "<<endl;
  for(int i = 0; i < c->students.size();i++)
  {
    cout<<c->students[i]->name<<endl;
  }
  cout<<""<<endl;
}
void enroll(Student* s, Course* c)
{
  s->courses.push_back(c);
  c->students.push_back(s);
}

int main() {

  Student names[4];
  names[0].name = "Tom";
  names[1].name = "Jerry";
  names[2].name = "Alfred";
  names[3].name = "Bob";
  Course subject[3];
  subject[0].name = "Calculus III";
  subject[1].name = "Organic Chemistry";
  subject[2].name = "Physics 101";
  enroll(&names[0], &subject[0]);
  enroll(&names[0], &subject[1]);
  enroll(&names[0], &subject[2]);
  enroll(&names[1], &subject[1]);
  enroll(&names[1], &subject[2]);
  enroll(&names[2], &subject[0]);
  enroll(&names[2], &subject[2]);
  enroll(&names[3], &subject[0]);
  enroll(&names[3], &subject[2]);
  for(int i = 0; i < 4; i++)
  {
    print_student(&names[i]);
  }
  for(int i = 0; i < 3; i++)
  {
    print_course(&subject[i]);
  }
  return 0;
}
