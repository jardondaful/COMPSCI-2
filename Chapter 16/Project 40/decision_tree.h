#ifndef DECISION_TREE_H
#define DECISION_TREE_H
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int ANSWER_NO = 1;
const int ANSWER_YES = 2;
const int ANSWER_UNDETERMINED = 3;

class Fact
{
public:
  Fact(int id);
  int get_id() const;
  void set_criterion(string question, bool answer);
  bool get_criterion(string question) const;
private:
  int id;
  unordered_map<string, bool> criteria;
};

class Criteria
{
public:
  Criteria(string data);
  void set_uncertainty(double p);
  double get_uncertainty() const;
  string get_data() const;
private:
  string data;
  double uncertainty;
};

class Node
{
private:
  string question;
  int answer;
  Node *left;
  Node *right;
  friend class DecisionTree;
};

class DecisionTree
{
public:
  DecisionTree(vector<Criteria *> &criteria, vector<Fact *> &facts, Criteria *objective);
  void insert(string question, int answer);
  void decide();

private:
  void add_node(Node *parent, Node *new_node) const;
  Node *root;
  Criteria *objective;
  vector<Criteria *> criteria;
  vector<Fact *> facts;
};

double uncertainty(double p);
bool sort_by_uncertainty(Criteria *a, Criteria *b);
double weighted_uncertainty(const string &objective, const string &criteria, const vector<Fact *> &facts);
void load_data_from_filestream(ifstream &in_file, vector<Criteria *> &criteria, vector<Fact *> &facts);

#endif
