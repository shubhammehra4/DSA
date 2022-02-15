#include <bits/stdc++.h>
using namespace std;

int rangedBinarySearch(vector<int> &arr, int target, int left, int right)
{
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int exponentialSearch(vector<int> &arr, int target)
{
    if (arr[0] == target)
        return 0;

    int n = arr.size();
    int i = 1;
    while (i < n && arr[i] <= target)
        i = i * 2;

    return rangedBinarySearch(arr, target, i / 2, min(i, n - 1));
}
