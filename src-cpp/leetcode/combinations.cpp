#include <bits/stdc++.h>
using namespace std;

// backtrack
void backtrack(vector<vector<int>> &res, vector<int> &comb, int n, int k)
{
    if (k == 0)
    {
        res.push_back(comb);
        return;
    }

    if (n > k)
        backtrack(res, comb, n - 1, k);
    comb.push_back(n);
    backtrack(res, comb, n - 1, k - 1);
    comb.pop_back();
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> t;
    backtrack(res, t, n, k);

    return res;
}

// backtracking less operations & global state
vector<vector<int>> res;
vector<int> v;

void dfsUtil(int i, int k, const int &n)
{
    for (int j = i + 1; j <= n; j++)
    {
        v[v.size() - k] = j;
        if (k > 1)
            dfsUtil(j, k - 1, n);
        else
            res.push_back(v);
    }
}

vector<vector<int>> combine(int n, int k)
{
    v.resize(k);
    dfsUtil(0, k, n);

    return res;
}

// backtracking
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;

    function<void(vector<int> &, int)> combineUtil = [&res, &k, &n, &combineUtil](vector<int> &r, int i) -> void
    {
        if (res.size() > k)
            return;

        if (r.size() == k)
        {
            res.push_back(r);
            return;
        }

        for (int j = i + 1; j <= n; j++)
        {
            r.push_back(j);
            combineUtil(r, j);
            r.pop_back();
        }
    };

    vector<int> t;
    combineUtil(t, 0);

    return res;
}