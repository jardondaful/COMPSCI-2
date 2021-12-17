#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node* next;
};

void printList(struct Node*);

void push(struct Node **head_ref, int new_data)
{
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void printList(struct Node *head)
{
  if(!head)
  {
    return;
  }
  while (head->next!= NULL)
  {
    cout<<head->data<<" -> ";
    head = head-> next;
  }
  cout<<head->data<<endl;
}

Node* find_mid(Node *head)
{
  Node *temp = head;
  Node *slow = head;
  Node *fast = head;
  while(fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next;
  }
  if(fast)
  {
    slow = slow->next;
  }
  return slow;
}

void modify(struct Node *head, struct Node *slow)
{
  stack<int> a;
  Node *temp = head;
  while(slow)
  {
    a.push(slow->data);
    slow = slow->next;
  }
  while(!a.empty())
  {
    temp->data = temp->data = a.top();
    temp = temp -> next;
    a.pop();
  }
}

void remove(Node** root, int value)
{
  if(*root == NULL)
  {
    return;
  }
  Node* previous = *root;
  Node* current = *root;
  if(current->data == value && current != NULL)
  {
    *root=current->next;
    delete(current);
    return;
   }
   while(current != NULL && current->data != value)
   {
    previous = current;
    current = current->next;
   }
   if(current == NULL)
   {
      return;
   }
   previous->next = current->next;
   delete(current);
}

int main() 
{
  struct Node *head = NULL, *mid;
  push(&head, 9);
  push(&head, 8);
  push(&head, 5);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);
  mid = find_mid(head);
  modify(head, mid);
  cout<<"The linked list using a dummy node is: "<<endl<<endl;
  printList(head);
  remove(&head, 1);
  remove(&head, 3);
  cout<<"The linked list after deleting the values 1 and 3 is: "<<endl;
  printList(head);
  return 0;
}
