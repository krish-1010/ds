#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[])
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }

    while (i < size1)
    {
        merged[k++] = arr1[i++];
    }

    while (j < size2)
    {
        merged[k++] = arr2[j++];
    }
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int size1 = 5;
    const int size2 = 7;

    int arr1[size1] = {3, 8, 12, 15, 20};
    int arr2[size2] = {1, 5, 9, 10, 13, 18, 25};

    // Sorting arrays using bubble sort
    bubbleSort(arr1, size1);
    bubbleSort(arr2, size2);

    cout << "Sorted Array 1: ";
    printArray(arr1, size1);

    cout << "Sorted Array 2: ";
    printArray(arr2, size2);

    // Merging arrays
    const int mergedSize = size1 + size2;
    int merged[mergedSize];
    mergeArrays(arr1, size1, arr2, size2, merged);

    cout << "Merged and Sorted Array: ";
    printArray(merged, mergedSize);

    return 0;
}
