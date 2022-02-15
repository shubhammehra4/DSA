#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int mid = left + ((right - left) / 2);

        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    return arr[left] >= target ? left : -1;
}

int *upperBoundPtr(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int mid = left + ((right - left) / 2);

        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    return arr[left] >= target ? &arr[left] : nullptr;
}