#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;

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

int *binarySearchPtr(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        if (arr[mid] == target)
            return &arr[mid];

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return nullptr;
}

// Range Inclusive
int rangedBinarySearch(vector<int> &arr, int target, int left, int right)
{
    if (left < 0 || right >= arr.size() || left > right)
        throw invalid_argument("Invalid Range");

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