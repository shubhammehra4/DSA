#include <bits/stdc++.h>
using namespace std;

/**
 * approach
 *  divide the array into 2 parts, after sorrting the 2 parts merge them back
 *
 * properties
    - stable
    - divide and conquer
    - not in place sorting
    - slower for small inputs
    - avg case O(n * logn)
 */

void merge(vector<int> &arr, int l, int mid, int r)
{
    int n = mid - l + 1;
    int m = r - mid;
    vector<int> left(begin(arr) + l, begin(arr) + mid + 1);
    vector<int> right(begin(arr) + mid + 1, begin(arr) + r + 1);
    // alter
    // vector<int> left(n);
    // vector<int> right(m);

    // for (int i = 0; i < n; i++)
    //     left[i] = arr[l + i];
    // for (int j = 0; j < m; j++)
    //     right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;
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

// recursive
void mergeSort(vector<int> &arr)
{
    return mergeSort(arr, 0, size(arr) - 1);
}

// iterative
void mergeSort(vector<int> &arr)
{
    int n = arr.size();

    // Bottom Up Merging
    for (int intervalSize = 1; intervalSize < n; intervalSize *= 2)
    {
        for (int l = 0; l < n - 1; l += 2 * intervalSize)
        {
            int mid = min(l + intervalSize - 1, n - 1);
            int r = min(l + 2 * intervalSize - 1, n - 1);

            merge(arr, l, mid, r);
        }
    }
}
