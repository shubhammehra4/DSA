#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> sPair;

class Comp
{
public:
    bool operator()(sPair &a, sPair &b)
    {
        if (a.first != b.first)
            return a.first < b.first;

        return a.second > b.second;
    }
};

vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string, int> m;
    for (auto w : words)
        m[w]++;

    priority_queue<sPair, vector<sPair>, Comp> pq;

    for (auto it : m)
        pq.push({it.second, it.first});

    vector<string> res;
    while (!pq.empty() & k-- > 0)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}

// Alternative
// Bucket Sort
vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string, int> cnt;
    vector<vector<string>> bucket(words.size() + 1);

    for (auto w : words)
        cnt[w]++;

    for (auto it : cnt)
        bucket[it.second].push_back(it.first);

    vector<string> res(k);
    int n = 0;
    for (int i = bucket.size() - 1; i >= 0; i--)
    {
        if (bucket[i].empty())
            continue;

        sort(bucket[i].begin(), bucket[i].end());
        for (auto s : bucket[i])
        {
            res[n++] = s;

            if (n == k)
                return res;
        }
    }

    return res;
}