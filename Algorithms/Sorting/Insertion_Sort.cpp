#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int n)
{
    int j, key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {2, 67, 89, 4, 34, 25, 67, 90, 32, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);

    return 0;
}