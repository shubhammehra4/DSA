#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];
    int partIdx = left - 1;
    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            partIdx++;
            swap(arr[partIdx], arr[j]);
        }
    }
    swap(arr[partIdx + 1], arr[right]);

    return partIdx + 1;
}

void quickSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int partIdx = partition(arr, left, right);

        quickSort(arr, left, partIdx - 1);
        quickSort(arr, partIdx + 1, right);
    }
}
