// Use baby.txt when program prompts for input to see that program works. First 4 lines of babynames.txt have commas manually inserted into the numbers to show that the program can handle numbers with commas)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void process_name(ifstream& in_file, double& total)
{
  string name;
  //my way of handling comma separated numbers is to simply treat the number like another string 
  string count;
  double percent;
  in_file>>name>>count>>percent;
  if(in_file.fail())
  {
    return;
  }
  if(total>0)
  {
    cout<<name<<" ";
  }
  total = total - percent;
}

int main() 
{
  //my way of getting the user to enter the file name is to have them also enter in the extension
  string name;
  cout<<"Please enter the file name of choice, including the file extension: ";
  cin>>name;
  ifstream in_file;
  in_file.open(name);
  if(in_file.fail())
  {
    return 0;
  }
  double boy_total = 50;
  double girl_total = 50;
  while(boy_total>0||girl_total>0)
  {
    int rank;
    in_file>>rank;
    cout<<rank<<" ";
    process_name(in_file, boy_total);
    process_name(in_file, girl_total);
    cout<<endl;
  }
  return 0;
}
