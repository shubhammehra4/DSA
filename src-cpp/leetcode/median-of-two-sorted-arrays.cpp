#include <bits/stdc++.h>
using namespace std;

// optimized O(log(min(m,n)))
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    if (m > n)
        return findMedianSortedArrays(nums2, nums1);

    int l = 0, r = m;
    int len = m + n;

    while (l <= r)
    {
        int partitionX = (l + r) / 2;
        int partitionY = ((len + 1) / 2) - partitionX;

        int leftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int rightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

        int leftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int rightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        if (leftX <= rightY && leftY <= rightX)
        {
            if (len % 2 == 0)
                return (double)(max(leftX, leftY) + min(rightX, rightY)) / 2.0;
            else
                return (double)(max(leftX, leftY));
        }
        else if (leftX > rightY)
            r = partitionX - 1;
        else
            l = partitionX + 1;
    }

    return -1.0;
}

// brute-force O(m+n)
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    vector<int> res(n + m);
    auto mergeTwoSortedArrays = [&res, n, m](vector<int> &nums1, vector<int> &nums2) -> void
    {
        int i = 0, j = 0, k = 0;

        while (i < n && j < m)
        {
            if (nums1[i] <= nums2[j])
                res[k++] = nums1[i++];
            else
                res[k++] = nums2[j++];
        }

        while (i < n)
            res[k++] = nums1[i++];

        while (j < m)
            res[k++] = nums2[j++];
    };

    mergeTwoSortedArrays(nums1, nums2);
    int len = n + m;

    if (len % 2 == 0)
        return ((double)res[len / 2] + (double)res[(len / 2) - 1]) / 2.0;

    return (double)res[len / 2];
}