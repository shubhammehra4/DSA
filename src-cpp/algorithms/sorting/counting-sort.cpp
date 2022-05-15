#include <bits/stdc++.h>
using namespace std;

/**
 * approach
 *  count the occurences of each element in a specific range and,
 *  then decide their index in the sorted array
 *
 * properties
    - not based on comparisons
    - not stable (can be made stable with changes)
    - not in place sorting
    - avg case O(n) with O(range) space
 */

void countingSort(vector<int> &arr)
{
    int n = size(arr);
    auto minmax = minmax_element(begin(arr), end(arr));
    int min = *minmax.first;
    int max = *minmax.second;
    int range = max - min + 1;

    vector<int> count(range, 0);
    vector<int> sorted(n);
    for (auto a : arr)
        count[a - min]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int pos = count[arr[i] - min] - 1;
        sorted[pos] = arr[i];

        count[arr[i] - min]--;
    }

    arr = move(sorted);
}