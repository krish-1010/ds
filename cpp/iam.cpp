#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int val = 0;
    int size = 5;
    // for (int i = size - 1; i >= 1; i--)
    // {
    //     arr[i] = arr[i - 1];
    // }
    // arr[0] = val;

    // for (int j = 0; j <= 5; j++)
    // {
    //     cout << arr[j];
    // }
    int pos = 3;
    pos--;
    for (int i = size - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;

    for (int j = 0; j < 5; j++)
    {
        cout << arr[j];
    }
}