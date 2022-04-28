#include <bits/stdc++.h>
using namespace std;

/**
 * approach
 *  repeatedly swap the adjacent elements if they are in the wrong order
 *
 * properties
    - stable
    - in place sorting
    - avg case O(n*n)
    - best case O(n) already sorted
 */

// optimised (early exit)
void bubbleSort(vector<int> &arr)
{
    int n = size(arr);
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < (n - 1) - i; j++)
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }

        if (swapped == false)
            break;
    }
}

void bubbleSort(vector<int> &arr)
{
    int n = size(arr);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - 1) - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    }
}
