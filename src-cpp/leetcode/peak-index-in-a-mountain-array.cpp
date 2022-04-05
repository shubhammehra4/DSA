#include <bits/stdc++.h>
using namespace std;

// binary-search
int peakIndexInMountainArray(vector<int> &arr)
{
    int l = 0, r = arr.size() - 1;

    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] < arr[m + 1])
            l = m + 1;
        else
            r = m;
    }

    return l;
}

// brute-force
int peakIndexInMountainArray(vector<int> &arr)
{
    int i = 0;
    while (arr[i] < arr[i + 1])
        i++;
    return i;
}