#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
// node creation
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

// insert a newNode at the end of the list
void insertEnd(struct Node **head, int data)
{
  // allocate memory for node
  struct Node *newNode = new Node;

  // assign data to newNode
  newNode->data = data;

  // assign null to next of newNode
  newNode->next = NULL;

  // store the head node temporarily (for later use)
  struct Node *temp = *head;

  // if the linked list is empty, make the newNode as head node
  if (*head == NULL)
  {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }

  // if the linked list is not empty, traverse to the end of the linked list
  while (temp->next != NULL)
    temp = temp->next;

  // now, the last node of the linked list is temp

  // assign next of the last node (temp) to newNode
  temp->next = newNode;

  // assign prev of newNode to temp
  newNode->prev = temp;
}
void del_begin(struct Node **head, struct Node *del_node)
{
  if (*head == del_node)
    *head = del_node->next;

  if (del_node->prev != NULL)
    del_node->prev->next = del_node->next;

  free(del_node);
  cout << "\nFirst Node Deleted\n";
}
void del_end(struct Node *head)
{
  struct Node *ptr;

  ptr = head;
  while ((ptr->next)->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = NULL;
  free(ptr->next);
  cout << "\nLast Node Deleted\n";
}
void del_middle(struct Node *head)
{
  struct Node *node;
  int i, pos;
  cout << "\nEnter position to delete: ";
  cin >> pos;
  node = head;
  for (i = 1; node != NULL && i < pos; i++)
  {
    node = node->next;
  }

  if (pos == 1)
  {
    del_begin(&head, head);
  }

  else if (node != NULL)
  {
    node->prev->next = node->next;
    node->next->prev = node->prev;

    free(node); // Deleting the nth node
  }
  else
  {
    cout << "The given position is invalid!\n";
  }
}

// print the doubly linked list
void displayList(struct Node *node)
{
  struct Node *last;

  while (node != NULL)
  {
    cout << node->data << "->";
    last = node;
    node = node->next;
  }
  if (node == NULL)
    cout << "NULL\n";
}

int main()
{
  // clrscr();
  //  initialize an empty node
  struct Node *head = NULL;

  insertEnd(&head, 5);
  insertEnd(&head, 1);
  insertEnd(&head, 6);
  insertEnd(&head, 9);
  insertEnd(&head, 4);
  insertEnd(&head, 2);
  displayList(head);
  del_begin(&head, head);
  displayList(head);
  del_end(head);
  displayList(head);
  del_middle(head);
  displayList(head);
  getch();
}
