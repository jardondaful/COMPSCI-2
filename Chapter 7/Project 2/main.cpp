#include <iostream>
using namespace std;
struct student
{
  string first_name;
  string last_name;
  char course_grade;
};
int main()
{ 
  int size;
  cout<<"Please enter number of students in course: ";
  cin>>size;
  student* arr = new student[size] ;
  for(int i = 0; i < size; i++)
  {
    string f = "";
    string l = "";
    char g;
    cout<<"Please enter a student's first name: ";
    cin>>f;
    arr[i].first_name = f;
    cout<<"Please enter the student's last name: ";
    cin>>l;
    arr[i].last_name = l;
     cout<<"Please enter the student's grade: ";
    cin>>g;
    arr[i].course_grade = g;
    cout<<""<<endl;
  }
  cout<<"Students with grade A:"<<endl;
  for(int i = 0; i < size; i++)
  {
    if(arr[i].course_grade=='A')
    {
      cout<<arr[i].first_name<<" "<<arr[i].last_name << " " <<endl;
    }
  }
  cout<<""<<endl;
  cout<<"Students with grade B:"<<endl;
  for(int i = 0; i < size; i++)
  {
    if(arr[i].course_grade=='B')
    {
      cout<<arr[i].first_name<<" "<<arr[i].last_name << " " <<endl;
    }
  }
  cout<<""<<endl;
  cout<<"Students with grade C:"<<endl;
  for(int i = 0; i < size; i++)
  {
    if(arr[i].course_grade=='C')
    {
      cout<<arr[i].first_name<<" "<<arr[i].last_name << " " <<endl;
    }
  }
  cout<<""<<endl;
  cout<<"Students with grade D:"<<endl;
  for(int i = 0; i < size; i++)
  {
    if(arr[i].course_grade=='D')
    {
      cout<<arr[i].first_name<<" "<<arr[i].last_name << " " <<endl;
    }
  }
  cout<<""<<endl;
  cout<<"Students with grade F:"<<endl;
  for(int i = 0; i < size; i++)
  {
    if(arr[i].course_grade=='F')
    {
      cout<<arr[i].first_name<<" "<<arr[i].last_name << " " <<endl;
    }
  }
  cout<<""<<endl;
  return 0;
  return 0;
}
