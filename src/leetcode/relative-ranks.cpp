#include <bits/stdc++.h>
using namespace std;

string medals[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};

vector<string> findRelativeRanks(vector<int> &score)
{
    int n = score.size();
    priority_queue<pair<int, int>> ranks;
    for (int i = 0; i < n; i++)
        ranks.push({score[i], i});

    vector<string> res(n, "");

    for (int pos = 1; pos <= n; pos++)
    {
        auto r = ranks.top();
        ranks.pop();

        if (pos <= 3)
            res[r.second] = medals[pos - 1];
        else
            res[r.second] = to_string(pos);
    }

    return res;
}

// Better Approach
vector<string> findRelativeRanks(vector<int> &score)
{
    int n = score.size();
    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);

    sort(begin(idx), end(idx), [&score](int a, int b)
         { return score[a] > score[b]; });

    vector<string> res(n, "");
    for (auto pos = 0; pos < n; pos++)
    {
        res[idx[pos]] = pos < 3 ? medals[pos] : to_string(pos + 1);
    }

    return res;
}