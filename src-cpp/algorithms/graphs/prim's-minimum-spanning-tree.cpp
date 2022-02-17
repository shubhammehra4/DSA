#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int start;
    int end;
    int cost;
};

auto comparator = [](const edge &a, const edge &b) -> bool
{
    return a.cost > b.cost;
};

auto primsMinimumSpannigTree(vector<vector<edge>> &adjLists, int start = 0)
{
    int n = adjLists.size();
    vector<int> visited(n, false);
    priority_queue<edge, vector<edge>, decltype(comparator)> pq(comparator);

    int m = n - 1; // number of edges in MST
    int edgeCount = 0;
    int mstCost = 0;
    vector<edge> mstEdges;

    auto addEdges = [&adjLists, &pq, &visited](int src) -> void
    {
        visited[src] = true;

        for (auto edge : adjLists[src])
            if (!visited[edge.end])
                pq.push(edge);
    };

    addEdges(start);

    while (!pq.empty() && edgeCount != m)
    {
        auto edge = pq.top();
        pq.pop();
        auto nodeIndex = edge.end;

        if (!visited[nodeIndex])
        {
            edgeCount++;
            mstEdges.push_back(edge);
            mstCost += edge.cost;

            addEdges(nodeIndex);
        }
    }

    if (edgeCount != m)
        return make_pair(-1, vector<edge>());

    return make_pair(mstCost, mstEdges);
}