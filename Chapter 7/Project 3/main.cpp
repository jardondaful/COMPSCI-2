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
  int grade;
  char g;
  for(int i = 0; i < size; i++)
  {
    grade = 0;
    string f = "";
    string l = "";
    char g = 'E';
    cout<<"Please enter a student's first name: ";
    cin>>f;
    arr[i].first_name = f;
    cout<<"Please enter the student's last name: ";
    cin>>l;
    arr[i].last_name = l;
    for(int j = 0; j < 10; j++)
    {
     int quiz_score;
     cout<<"Please enter one of the student's quiz scores: ";
     cin>>quiz_score;
     grade+=quiz_score;
      
    }
    if(grade>=90)
    {
      g = 'A';
    }
    else if(grade>=80)
    {
      g = 'B';
    }
    else if(grade>=70)
    {
      g = 'C';
    }
    else if(grade>=60)
    {
      g = 'D';
    }
    else
    {
      g = 'F';
    }
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
