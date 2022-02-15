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

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSortIter(vector<int> &arr)
{
    int n = arr.size();
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

int main()
{
    vector<int> a = {-1, 2, 8, 7, 9};

    mergeSort(a, 0, a.size() - 1);

    for (auto &i : a)
        cout << i << " ";

    return 0;
}