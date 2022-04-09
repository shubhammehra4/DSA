#include <bits/stdc++.h>
using namespace std;

// binary search
int getPower(const vector<int> &row)
{
    auto it = lower_bound(begin(row), end(row), 0, greater<int>());
    return it - row.begin();
}
vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    set<pair<int, int>> st;
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        int power = getPower(mat[i]);
        st.emplace(power, i);

        if (st.size() > k)
            st.erase(--st.end());
    }

    vector<int> res;
    for (auto &p : st)
        res.push_back(p.second);

    return res;
}

// accumulate
vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        int power = accumulate(begin(mat[i]), end(mat[i]), 0);
        pq.push({power, i});
    }

    vector<int> res;
    while (k-- && !pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}