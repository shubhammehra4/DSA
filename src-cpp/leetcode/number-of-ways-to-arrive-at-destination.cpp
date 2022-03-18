#include <bits/stdc++.h>
using namespace std;

#define ll long long

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, ll>>> graph(n + 1);
    for (auto x : roads)
    {
        graph[x[0]].push_back({x[1], x[2]});
        graph[x[1]].push_back({x[0], x[2]});
    }

    const ll mod = 1e9 + 7;
    vector<ll> cnt(n, 1);

    vector<ll> dist(n, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto [nodeTime, node] = pq.top();
        pq.pop();

        for (auto [child, childTime] : graph[node])
        {
            if (dist[child] == 0 || dist[child] >= nodeTime + childTime)
            {
                if (dist[child] == nodeTime + childTime)
                    cnt[child] = (cnt[child] + cnt[node]) % mod;
                else
                {
                    dist[child] = nodeTime + childTime;
                    cnt[child] = cnt[node];
                    pq.push({dist[child], child});
                }
            }
        }
    }

    return cnt[n - 1];
}