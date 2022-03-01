#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n)
{
    vector<int> ans(n + 1);

    ans[0] = 0;

    for (int i = 1; i <= n; i++)
        ans[i] = ans[i >> 1] + (i & 1);
    //  ans[i] = ans[i / 2] + i % 2;
    //  ans[i] = ans[i & (i - 1)] + 1;

    return ans;
}

vector<int> countBits(int num)
{
    vector<int> ans(num + 1);
    ans[0] = 0;

    for (int i = 1; i <= num; i++)
    {
        if (i % 2 == 0)
            ans[i] = ans[i / 2];
        else
            ans[i] = ans[i - 1] + 1;
    }

    return ans;
}

// naive
vector<int> countBits(int n)
{
    vector<int> ans;

    for (int i = 0; i <= n; i++)
        ans.push_back(__builtin_popcount(i));

    return ans;
}