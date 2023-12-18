#include <iostream>

using namespace std;

// Function to perform binary search in a sorted array
int binarySearch(const int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid; // Element found, return its index
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Element not found
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
    const int size = 10;
    int sortedArray[size] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    cout << "Sorted Array: ";
    printArray(sortedArray, size);

    int target;
    cout << "Enter the element to search for: ";
    cin >> target;

    // Perform binary search
    int index = binarySearch(sortedArray, size, target);

    if (index != -1)
    {
        cout << "Element " << target << " found at index " << index << "." << endl;
    }
    else
    {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
