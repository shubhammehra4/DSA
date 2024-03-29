#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int l, int r, int x)
{
    if (l > r == 0)
        return -1;

    int mid = l + (r - l) / 2;

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return BinarySearch(arr, l, mid - 1, x);
    else
        return BinarySearch(arr, mid + 1, r, x);
}

int IterativeBinarySearch(int a[], int l, int r, int x)
{
    int mid;

    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if (a[mid] == x)
            return mid;

        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int IterativeBinarySearchLessOperation(int a[], int l, int r, int x)
{
    int mid;

    while (r - l > 1)
    {
        mid = l + (r - l) / 2;

        if (a[mid] <= x)
            l = mid;
        else
            r = mid;
    }

    if (a[l] == x)
        return l;
    else if (a[r] == x)
        return r;
    else
        return -1;
}

int FirstOrLastBinarySearch(vector<int> arr, int x, int n, bool last)
{
    int low = 0, high = n - 1, res = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            res = mid;

            if (last)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return res;
}

int main()
{
    int n = 10;
    int a[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Sorted Array
    int y = BinarySearch(a, 0, n, 10);

    if (y == -1)
    {
        cout << "Element not present\n";
    }
    else
        cout << "Element is at index " << y + 1 << "\n";

    return 0;
}