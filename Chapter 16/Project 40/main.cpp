//This program reads in a file that contains the criteria and objective (data.txt), one per line, followed by a blank line and a sequence of lines, each containing a fact (that is, a sequence of Y and N for the criteria and objective). The program's decision tree leaves indicate whether the objective is fulfilled or not. The user provides inputs for each criterion, and the program prints the objective when it is determined.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "decision_tree.h"
using namespace std;

int main()
{
  cout<<"_______________________________________________________"<<endl<<endl;
  cout<<"      Decision Tree Implementation for Animals"<<endl;
  cout<<"_______________________________________________________"<<endl;
  ifstream in_file("data.txt");
  vector<Criteria *> criteria;
  vector<Fact *> facts;
  load_data_from_filestream(in_file, criteria, facts);
  auto *objective = criteria[criteria.size() - 1];
  criteria.pop_back();
  cout << endl<<"There are a total of " << facts.size() << " facts in " << criteria.size() << " criteria" << endl;
  cout << "\nThe objective: " << objective->get_data() << endl;
  cout<<"\n-------------------------------------------"<<endl<<endl;
  DecisionTree tree{criteria, facts, objective};
  tree.decide();
  return 0;
}
