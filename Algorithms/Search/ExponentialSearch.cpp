#include <bits/stdc++.h>
using namespace std;

int BinarySearch (int arr[], int l, int r , int x)
{
    if (r - l == 0) return -1;

    int mid = l + (r - l) / 2;

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x )
        return binarySearch (arr, l, mid - 1, x);
    else if (arr[mid] < x)
        return binarySearch (arr, mid + 1, r, x);
    else
        return -1;
}

int ExponentialSearch (int a[], intn, int x)
{
    if (arr[0] == x)
        return 0;

    int i = 1;

    while (i < n && arr[i] <= x)
        i = i * 2;

    if (i > n) return -1;

    return binarySearch (a, i / 2, min (i, n), x)
}


int main()
{
    int n = 10;
    int a[n] = {1, 4, 5, 9, 14, 17, 20, 27, 34, 55}; // Sorted array
    int y = ExponentialSearch (a, n, 27);

    if (y == -1)
    {
        cout << "Element not present\n";
    }

    else
        cout << "Element is at index " << y + 1 << "\n";

    return 0;
}