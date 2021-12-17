#include <bits/stdc++.h>
using namespace std;
 
/* structure for a node */
class Node 
{
  public:
    int data;
    Node* next;
};
 
void insert(Node** head_ref, int data)
{
  Node* ptr1 = new Node();
  ptr1->data = data;
  ptr1->next = *head_ref;
  if (*head_ref != NULL) 
  {
    Node* temp = *head_ref;
    while (temp->next != *head_ref)
    {
      temp = temp->next;
      temp->next = ptr1;
    }
  }
    else
    {
      ptr1->next = ptr1; 
    }
 
  *head_ref = ptr1;
}

void display(Node* head)
{
  Node* temp = head;
  if (head != NULL) {
    do 
    {
      cout << temp->data << " -> ";
      temp = temp->next;
    } while (temp != head);
  }
  cout << endl;
}
 
void deleteNode(Node** head, int key) 
{
  if (*head == NULL)
  {
    return;
  }
  if((*head)->data==key && (*head)->next==*head)
    {
      free(*head);
      *head=NULL;
      return;
    }
    Node *last=*head,*d;
    if((*head)->data==key) 
    {
      while(last->next!=*head)
      {
        last=last->next;
      }
      last->next=(*head)->next;
      free(*head);
      *head=last->next;
    }
    while(last->next!=*head&&last->next->data!=key) 
    {
      last=last->next;
    }
    if(last->next->data==key) 
    {
      d=last->next;
      last->next=d->next;
      free(d);
    }
  }
 
int main()
{
    Node* head = NULL;
    insert(&head, 2);
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 8);
    insert(&head, 9);
    insert(&head, 10);
 
    cout << "The following is the circular list: ";
    display(head);
    deleteNode(&head, 7);
    deleteNode(&head, 9);
    cout << "The following is the circular list after the values 7 and 9 are deleted: ";
    display(head);
 
    return 0;
} 
