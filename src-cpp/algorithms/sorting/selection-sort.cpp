#include <bits/stdc++.h>
using namespace std;

/**
 * approach
 *  repeatedly find the min element from unsorted part and put it at the beginning
 *
 * properties
    - unstable (can be made stable)
    - in place sorting
    - avg case O(n*n)
 */

// stable
// instead of swapping insert key in it's place and push every element forward
void selectionSort(vector<int> &arr)
{
    int n = size(arr);
    for (int i = 0; i < n - 1; i++)
    {
        int selectedIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[selectedIdx])
                selectedIdx = j;

        int key = arr[selectedIdx];
        while (selectedIdx > i)
        {
            arr[selectedIdx] = arr[selectedIdx - 1];
            selectedIdx--;
        }
        arr[i] = key;
    }
}

// unstable
void selectionSort(vector<int> &arr)
{
    int n = size(arr);
    for (int i = 0; i < n - 1; i++)
    {
        int selectedIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[selectedIdx])
                selectedIdx = j;

        swap(arr[i], arr[selectedIdx]);
    }
}