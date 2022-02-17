#include <bits/stdc++.h>
using namespace std;

void MinSparseTable(vector<int> &nums)
{
    int n = nums.size();
    int P = floor(log2(n));

    vector<int> log2Lookup(n + 1, 0);
    for (int i = 2; i <= n; i++)
        log2Lookup[i] = log2Lookup[i / 2] + 1;

    vector<vector<int>> sparseTable(P + 1, vector<int>(n, INT_MIN));
    vector<vector<int>> indexTable(P + 1, vector<int>(n, INT_MIN)); // index of the min ele

    for (int i = 0; i < n; i++)
    {
        sparseTable[0][i] = nums[i];
        indexTable[0][i] = i;
    }

    for (int p = 1; p <= P; p++)
    {
        for (int i = 0; i + (1 << p) <= n; i++)
        {
            int left = sparseTable[p - 1][i];
            int right = sparseTable[p - 1][i + (1 << (p - 1))];

            sparseTable[p][i] = min(left, right);

            if (left <= right)
                indexTable[p][i] = indexTable[p - 1][i];
            else
                indexTable[p][i] = indexTable[p - 1][i + (1 << (p - 1))];
        }
    }

    // Overlap friendly - O(1)
    auto minQuery = [&sparseTable, &log2Lookup](int l, int r) -> int
    {
        int len = r - l + 1;
        int p = log2Lookup[len];
        int k = 1 << p;

        int left = sparseTable[p][l];
        int right = sparseTable[p][r - k + 1];

        return min(left, right);
    };

    // Not Overlap friendly - O(log(n))
    auto cascadingMinQuery = [&sparseTable, &log2Lookup](int l, int r) -> int
    {
        int minVal = INT_MAX;
        for (int p = log2Lookup[r - l + 1]; l <= r; p = log2Lookup[r - l + 1])
        {
            minVal = min(minVal, sparseTable[p][l]);
            l += 1 << p;
        }
        return minVal;
    };

    auto minIndexQuery = [&sparseTable, &indexTable, &log2Lookup](int l, int r) -> int
    {
        int len = r - l + 1;
        int p = log2Lookup[len];
        int k = 1 << p;

        int left = sparseTable[p][l];
        int right = sparseTable[p][r - k + 1];

        if (left <= right)
            return indexTable[p][l];
        return indexTable[p][r - k + 1];
    };
}