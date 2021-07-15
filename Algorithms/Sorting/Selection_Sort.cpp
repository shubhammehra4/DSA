#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n)
{
    int k;
    for (int i = 0; i < n - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        swap(arr[i], arr[k]);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {1, 56, 23, 13, 45, 90, 76, 55, 23, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);

    return 0;
}