#include<iostream>
#include <string>
using namespace std;

// Template function to print an array
template <typename T, int N>
void printArray(T(&arr)[N])
{
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Template function for selection sort
template <typename T, int N>
void selectionSort(T(&arr)[N])
{
    for (int i = 0; i < N - 1; i++)
    {
        int smallSub = i;

        // Find the smallest element in the remaining array
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[smallSub])
            {
                smallSub = j;
            }
        }

        // Swap the smallest element with the first element
        // of the unsorted portion
        T temp = arr[i];
        arr[i] = arr[smallSub];
        arr[smallSub] = temp;
    }
}

int main()
{
    // Test with an integer array of size 5
    int intArray[5] = { 64, 25, 12, 22, 11 };

    cout << "Original integer array: ";
    printArray(intArray);

    selectionSort(intArray);

    cout << "Sorted integer array: ";
    printArray(intArray);

    // Test with a string array of size 4
    string stringArray[4] = { "apple", "orange", "banana", "grape" };

    cout << "\nOriginal string array: ";
    printArray(stringArray);

    selectionSort(stringArray);

    cout << "Sorted string array: ";
    printArray(stringArray);

    return 0;
}
