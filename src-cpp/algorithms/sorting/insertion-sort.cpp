#include <bits/stdc++.h>
using namespace std;

/**
 * approach
 * insert elements in the sorted way by comparing them with predecessors
 *
 * properties
    - stable
    - in place sorting
    - avg case O(n*n)
    - best case O(n) already sorted
    - worst case reverse sorted array
 */

void insertionSort(vector<int> &arr)
{
    int n = size(arr);
    for (int i = 1; i < n; i++)
    {
        int idx = i - 1;
        while (idx >= 0 && arr[idx] > arr[i])
        {
            arr[idx + 1] = arr[idx];
            idx--;
        }

        arr[idx + 1] = arr[i];
    }
}