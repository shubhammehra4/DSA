#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int n = mid - low + 1;
    int m = high - mid;
    vector<int> left(n);
    vector<int> right(m);

    for (int i = 0; i < n; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < m; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n && j < m)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < n)
        arr[k++] = left[i++];

    while (j < m)
        arr[k++] = right[j++];
}

void mergeSort(vector<int> &arr)
{
    int n = arr.size();
    int curr_size;
    int left_start;

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

void sortColors(vector<int> &nums)
{
    mergeSort(nums);
}