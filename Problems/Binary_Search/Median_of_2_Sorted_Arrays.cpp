#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &a, vector<int> &b)
{
    int m = a.size();
    int n = b.size();
    if (m > n)
        return findMedianSortedArrays(b, a);

    int l = 0, r = m;
    while (l <= r)
    {
        int mid1 = l + (r - l) / 2;
        int mid2 = ((m + n + 1) / 2) - mid1;

        int leftX = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int rightX = (mid1 == m) ? INT_MAX : a[mid1];

        int leftY = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
        int rightY = (mid2 == n) ? INT_MAX : b[mid2];

        if (leftX <= rightY && leftY <= rightX)
        {
            if ((m + n) % 2 == 0)
                return (double)(max(leftX, leftY) + min(rightX, rightY)) / 2;
            else
                return (double)(max(leftX, leftY));
        }
        else if (leftX > rightY)
            r = mid1 - 1;
        else
            l = mid1 + 1;
    }

    return -1.0;
}

int main()
{
    return 0;
}