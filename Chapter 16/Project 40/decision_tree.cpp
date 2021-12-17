#include "decision_tree.h"

using namespace std;

Fact::Fact(int id) : id{id} {}
int Fact::get_id() const { return id; }
void Fact::set_criterion(string question, bool answer) { criteria[question] = answer; }
bool Fact::get_criterion(string question) const { return criteria.at(question); }

Criteria::Criteria(string data) : data{data} {}
void Criteria::set_uncertainty(double p) { uncertainty = p; }
double Criteria::get_uncertainty() const { return uncertainty; }
string Criteria::get_data() const { return data; }

DecisionTree::DecisionTree(vector<Criteria *> &criteria, vector<Fact *> &facts, Criteria *objective)
    : objective{objective}, criteria{criteria}, facts{facts}
{
  root = nullptr;
  for (auto &c : criteria)
  {
    double uncertainty = weighted_uncertainty(objective->get_data(), c->get_data(), facts);
    c->set_uncertainty(uncertainty);
  }
  sort(criteria.begin(), criteria.end(), sort_by_uncertainty);
  for (auto &c : criteria)
  {
    vector<Fact *> positive_facts;
    vector<Fact *> negative_facts;

    for (auto &fact : facts)
    {
      if (fact->get_criterion(c->get_data()))
      {
        positive_facts.push_back(fact);
      }
      else
      {
        negative_facts.push_back(fact);
      }
    }
    if (positive_facts.size() == 1)
    {
      insert(c->get_data(), ANSWER_YES);
      facts = negative_facts;
    }
    else if (negative_facts.size() == 1)
    {
      insert(c->get_data(), ANSWER_NO);
      facts = positive_facts;
    }
    else
    {
      insert(c->get_data(), ANSWER_UNDETERMINED);
    }
  }
}

void DecisionTree::insert(string question, int answer)
{
  Node *new_node = new Node;
  if (answer == ANSWER_UNDETERMINED)
  {
    new_node->answer = ANSWER_UNDETERMINED;
    new_node->left = nullptr;
    new_node->right = nullptr;
  }
  else
  {
    new_node->question = question;

    Node *answer_node = new Node;
    answer_node->answer = answer;
    if (answer == ANSWER_YES)
    {
      new_node->left = answer_node;
      new_node->right = nullptr;
    }
    else if (answer == ANSWER_NO)
    {
      new_node->left = nullptr;
      new_node->right = answer_node;
    }
  }
  if (root == nullptr)
  {
    root = new_node;
  }
  else
  {
    add_node(root, new_node);
  }
}

void DecisionTree::add_node(Node *parent, Node *new_node) const
{
  if (parent->right == nullptr)
  {
    parent->right = new_node;
  }
  else if (parent->right != nullptr && parent->right->answer == 0)
  {
    add_node(parent->right, new_node);
  }
  else if (parent->left == nullptr)
  {
    parent->left = new_node;
  }
  else if (parent->left != nullptr && parent->left->answer == 0)
  {
    add_node(parent->left, new_node);
  }
}

void DecisionTree::decide()
{
  Node *node = root;

  while (node->left != nullptr || node->right != nullptr || node->answer == 0)
  {
    string answer = "";
    do
    {
      if (cin.fail() || (answer != "y" && answer != "n" && answer != ""))
      {
        cout << "Error: The input is not valid. Try again." << endl;
        cin.clear();
        cin.ignore();
      }
      cout << node->question << " (type in 'y' for yes and 'n' for no):" << endl;
      cin >> answer;
    } while (cin.fail() || (answer != "y" && answer != "n"));

    if (answer == "y")
    {
      node = node->left;
    }
    if (answer == "n")
    {
      node = node->right;
    }
    cout<<endl;
  }
  cout<<"-------------------------------------------"<<endl<<endl;
  cout << "Based on your input(s), the answer to the objective '" << objective->get_data() << "' is ";
  switch (node->answer)
  {
  case ANSWER_NO:
    cout << "'no.'" << endl;
    break;
  case ANSWER_YES:
    cout << "'yes.'" << endl;
    break;
  default:
    cout << "Undetermined by given answers." << endl;
    break;
  }
}

double weighted_uncertainty(const string &objective, const string &criteria, const vector<Fact *> &facts)
{
  int total_facts = facts.size();

  double criteria_true = 0;
  double criteria_false = 0;

  double objective_true = 0;
  double objective_false = 0;

  for (auto &fact : facts)
  {
    if (fact->get_criterion(criteria) == true)
    {
      criteria_true++;
      if (fact->get_criterion(objective) == true)
      {
        objective_true++;
      }
    }
    else
    {
      criteria_false++;
      if (fact->get_criterion(objective) == false)
      {
        objective_false++;
      }
    }
  }

  return (criteria_true / total_facts) * uncertainty(objective_true / criteria_true) + (criteria_false / total_facts) * uncertainty(objective_false / criteria_false);
}

double uncertainty(double p)
{
  if (p == 0.0 || p == 1.0)
    return 0.0;

  double s = 1.0 - p;
  return -p * log2(p) - s * log2(s);
}

bool sort_by_uncertainty(Criteria *a, Criteria *b)
{
  return a->get_uncertainty() < b->get_uncertainty();
}

void load_data_from_filestream(ifstream &in_file, vector<Criteria *> &criteria, vector<Fact *> &facts)
{

  string line;
  bool is_fact = false;
  int index = 0;
  int factId = -1;

  while (!in_file.eof())
  {
    getline(in_file, line);
    if (line == "")
    {
      is_fact = true;
      index = 0;
      factId++;
      continue;
    }
    if (is_fact == false)
    {
      Criteria *c = new Criteria(line);
      criteria.push_back(c);
    }
    else
    {
      Fact *fact;

      if (index == 0)
      {
        fact = new Fact(factId);
        facts.push_back(fact);
      }
      else
      {
        fact = facts[factId];
      }
      fact->set_criterion(criteria[index]->get_data(), line == "Y");
    }
    index++;
  }
}
