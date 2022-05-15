#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<int> time(n + 1, INT_MAX); // dist
    time[0] = -1;
    time[k] = 0;

    for (int i = 0; i < n; i++)
    {
        bool shouldExit = true;

        for (auto &edge : times)
        {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];

            if (time[u] != INT_MAX && time[v] > time[u] + t)
            {
                time[v] = time[u] + t;
                shouldExit = false;
            }
        }

        if (shouldExit)
            break;
    }

    int res = *max_element(begin(time), end(time));

    return res == INT_MAX ? -1 : res;
}

// alter build a graph
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto &edge : times)
    {
        int u = edge[0];
        int v = edge[1];
        int t = edge[2];
        graph[u].push_back({t, v});
    }

    vector<int> time(n + 1, INT_MAX);
    time[0] = -1;
    time[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, k));

    while (!pq.empty())
    {
        auto edge = pq.top();
        pq.pop();
        for (auto neighbor : graph[edge.second])
        {
            int t = time[edge.second] + neighbor.first;
            if (t < time[neighbor.second])
            {
                time[neighbor.second] = t;
                pq.push(make_pair(t, neighbor.second));
            }
        }
    }

    int res = *max_element(begin(time), end(time));

    return res == INT_MAX ? -1 : res;
}