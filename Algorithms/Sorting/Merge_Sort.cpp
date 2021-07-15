// Divide & Conquer
// Stable
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r);

void RMergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        RMergeSort(arr, l, m);
        RMergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void IMergeSort(int arr[], int n)
{
    int curr_size;  // For current size of subarrays to be merged
    int left_start; // For picking starting index of left subarray to be merged

    // Bottom Up Merging
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
    {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
        {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            merge(arr, left_start, mid, right_end);
        }
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, n);
    // RMergeSort(arr, 0, n - 1);
    IMergeSort(arr, n);
    cout << "\nSorted array is \n";
    printArray(arr, n);

    return 0;
}