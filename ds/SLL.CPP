
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
class Node
{
public:
   int data;
   class Node *next;
};
void push(class Node **head, int nodeData)
{
   class Node *newNode1 = new Node;

   newNode1->data = nodeData;
   newNode1->next = (*head);

   (*head) = newNode1;
}
void insertAfter(class Node *prevNode, int nodeData)
{
   if (prevNode == NULL)
   {
      cout << "the given previous node is required,cannot be NULL";
      return;
   }
   class Node *newNode1 = new Node;
   newNode1->data = nodeData;
   newNode1->next = prevNode->next;
   prevNode->next = newNode1;
}
void append(class Node **head, int nodeData)
{
   class Node *newNode1 = new Node;

   class Node *last = *head;
   newNode1->data = nodeData;
   newNode1->next = NULL;
   if (*head == NULL)
   {
      *head = newNode1;
      return;
   }
   while (last->next != NULL)
      last = last->next;
   last->next = newNode1;
   return;
}
void displayList(class Node *node)
{
   while (node != NULL)
   {
      cout << node->data << "-->";
      node = node->next;
   }

   if (node == NULL)
      cout << "null";
}
int main()
{
   class Node *head = NULL;
   push(&head, 15);
   cout << "\nInsertion at beginning\n";
   displayList(head);
   cout << endl;
   push(&head, 25);
   displayList(head);
   cout << endl;
   push(&head, 35);
   displayList(head);
   cout << endl;
   cout << "\nInsertion at end\n";
   append(&head, 45);
   displayList(head);
   cout << endl;
   cout << "\nInsertion at middle\n";
   insertAfter(head->next, 55);
   displayList(head);
   cout << endl;

   cout << "\nFinal linked list: " << endl;
   displayList(head);

   return 0;
}
