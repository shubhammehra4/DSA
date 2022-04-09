#include <bits/stdc++.h>
using namespace std;

int threeSumMulti(vector<int> &arr, int target)
{
    unordered_map<int, long> c; // vector can also be used with given constraints
    for (int a : arr)
        c[a]++;

    long res = 0;
    for (auto it : c)
        for (auto it2 : c)
        {
            int i = it.first, j = it2.first;
            int k = target - i - j;

            if (!c.count(k))
                continue;

            if (i == j && j == k)
                res += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
            else if (i == j && j != k)
                res += c[i] * (c[i] - 1) / 2 * c[k];
            else if (i < j && j < k)
                res += c[i] * c[j] * c[k];
        }

    return res % int(1e9 + 7);
}