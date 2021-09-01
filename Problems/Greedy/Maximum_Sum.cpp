#include <bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>> &a)
{
    int n = a.size(), neg_cnt = 0;
    long long ans = 0;
    int min_elem = INT_MAX;
    for (auto i : a)
    {
        for (auto j : i)
        {
            ans += abs(j);
            min_elem = abs(j) < min_elem ? abs(j) : min_elem;
            if (j < 0)
                neg_cnt++;
        }
    }

    if (neg_cnt % 2 == 0)
        return ans;
    else
        return ans - 2 * min_elem;
}

int main()
{
    return 0;
}