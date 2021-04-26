#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (min > A[i][0])
            min = A[i][0];

        if (max < A[i][m - 1])
            max = A[i][m - 1];
    }

    int chk = (n * m + 1) / 2;

    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int count = 0;

        for (int i = 0; i < n; ++i)
            count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();

        // upper bound returns first element greter than mid

        if (count < chk)
            min = mid + 1; // median is greater than mid
        else
            max = mid;
    }

    return min;
}

int main()
{
    return 0;
}