#include <bits/stdc++.h>
using namespace std;

// binary-search
int findKthPositive(vector<int> &arr, int k)
{
    int l = 0, r = arr.size(), m;

    while (l < r)
    {
        m = (l + r) / 2;

        if (arr[m] - 1 - m < k)
            l = m + 1;
        else
            r = m;
    }

    return l + k;
}

// brute-force
int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();
    int j = 0, i;
    for (i = 1; i < 1001; i++)
    {
        if (j < n && arr[j] == i)
            j++;
        else
            k--;

        if (k == 0)
            return i;
    }

    while (k--)
        i++;

    return i - 1;
}