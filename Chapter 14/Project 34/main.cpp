#include<iostream>

using namespace std;

class Node
{
  public:
    int data;
    Node *next;
};

void insert(Node **root, int value)
{
   Node* newNode = new Node();
   newNode->data = value;
   if(root == NULL)
   {
      newNode->next = NULL;
      *root = newNode;
   }
   else
   {
    newNode->next = *root;
    *root= newNode;
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

void display(Node *root)
{
  cout<<"The singly-linked list is now the following: "<<endl;
  do
  {
    cout<<root->data<<" ";
    root = root->next;
  }while(root!=NULL);
  cout<<endl<<endl;
}

int main()
{
  Node *root = NULL;
  insert(&root,1);
  insert(&root,3);
  insert(&root,5);
  insert(&root,7);
  insert(&root,9);
  display(root);
  cout<<"The values 1 and 5 have been removed"<<endl<<endl;
  remove(&root, 1);
  remove(&root, 5);
  display(root);
}
