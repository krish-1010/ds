#include<iostream.h>
#define MAX_SIZE 100
#include<stdio.h>
#include<conio.h>
// Maximum size of the queue

class CircularQueue
{
private:
  int front, rear;
  int arr[MAX_SIZE];

public:
    CircularQueue ()
  {
    front = -1;
    rear = -1;
  }

  // Function to check if the queue is full
  int isFull()
  {
    if ((front == 0 && rear == MAX_SIZE - 1)
	|| (rear == (front - 1) % (MAX_SIZE - 1)))
      {
	return 1;
      }
    return 0;
  }

  // Function to check if the queue is empty
  int isEmpty ()
  {
    if (front == -1)
      {
	return 1;
      }
    return 0;
  }

  // Function to add an element to the queue
  void enQueue (int value)
  {
    if (isFull ()==1)
      {
	cout << "Queue is full." << endl;
      }
    else
      {
	if (front == -1)
	  {
	    front = 0;
	  }
	rear = (rear + 1) % MAX_SIZE;
	arr[rear] = value;
	cout << "Enqueued element: " << value << endl;
      }
  }

  // Function to remove an element from the queue
  int deQueue ()
  {
    int element;
    if (isEmpty ()==1)
      {
	cout << "Queue is empty." << endl;
	return -1;
      }
    else
      {
	element = arr[front];
	if (front == rear)
	  {
	    front = -1;
	    rear = -1;
	  }
	else
	  {
	    front = (front + 1) % MAX_SIZE;
	  }
	cout << "Dequeued element: " << element << endl;
	return element;
      }
  }

  // Function to display the elements in the queue
  void display ()
  {
    if (isEmpty ()==1)
      {
	cout << "Queue is empty." << endl;
      }
    else
      {
	cout << "Elements in the queue: ";
	int i;
	for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
	  {
	    cout << arr[i] << " ";
	  }
	cout << arr[i] << endl;
      }
  }
};

int main ()
{ clrscr();
  CircularQueue q;

  q.enQueue (10);
  q.enQueue (20);
  q.enQueue (30);
  q.enQueue (40);

  q.display ();

  q.deQueue ();
  q.deQueue ();

  q.display ();

  q.enQueue (50);
  q.enQueue (60);

  q.display ();

  getch();
  return 0;
}
