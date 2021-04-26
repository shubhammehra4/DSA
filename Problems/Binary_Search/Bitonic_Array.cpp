#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> a, int l, int r, int k, bool desc)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == k)
            return mid;
        if (desc)
        {
            if (a[mid] < k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (a[mid] > k)
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    return -1;
}

int findBitonicPoint(vector<int> a, int n, int l, int r)
{
    int m;
    int bP = 0;
    m = (r + l) / 2;
    if (a[m] > a[m - 1] && a[m] > a[m + 1])
        return m;

    else if (a[m] > a[m - 1] && a[m] < a[m + 1])
        bP = findBitonicPoint(a, n, m, r);

    else if (a[m] < a[m - 1] && a[m] > a[m + 1])
        bP = findBitonicPoint(a, n, l, m);

    return bP;
}

int searchBitonic(vector<int> &A, int B)
{
    int n = A.size();
    int bPoint = findBitonicPoint(A, n, 0, n - 1);

    if (B > A[bPoint])
        return -1;
    else if (B == A[bPoint])
        return bPoint;
    else
    {
        int temp = BinarySearch(A, 0, bPoint - 1, B, false);
        if (temp != -1)
            return temp;

        return BinarySearch(A, bPoint + 1, n - 1, B, true);
    }
}

int main()
{
    vector<int> arr = {-8, 1, 2, 3, 4, 5, -2, -3};

    int x = searchBitonic(arr, 1);
    if (x == -1)
        cout << "Element Not Found" << endl;
    else
        cout << "Element Found at index " << x << endl;

    return 0;
}
