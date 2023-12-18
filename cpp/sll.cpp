#include <iostream>
#include <conio.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int main()
{
    node n1;
    node n2(10);
    n1.next = &n2;
    cout << n1.data << endl;
    cout << n2.data << endl;
    cout << n1.next->data << endl;
}