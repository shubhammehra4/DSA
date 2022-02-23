#include <bits/stdc++.h>
using namespace std;

struct WeightedEdge
{
    int to;
    int weight; // cost to reach
};
auto comparator = [](const WeightedEdge &a, const WeightedEdge &b) -> bool
{
    return a.weight > b.weight;
};

auto primsMinimumSpannigTree(vector<vector<WeightedEdge>> &adjLists, int start = 0)
{
    int n = adjLists.size();
    vector<int> visited(n, false);
    priority_queue<WeightedEdge, vector<WeightedEdge>, decltype(comparator)> pq(comparator);

    int m = n - 1; // number of edges in MST
    int edgeCount = 0;
    int mstCost = 0;
    vector<WeightedEdge> mstEdges;

    auto addEdges = [&adjLists, &pq, &visited](int src) -> void
    {
        visited[src] = true;

        for (auto edge : adjLists[src])
            if (!visited[edge.to])
                pq.push(edge);
    };

    addEdges(start);

    while (!pq.empty() && edgeCount != m)
    {
        auto edge = pq.top();
        pq.pop();
        auto nodeIndex = edge.to;

        if (!visited[nodeIndex])
        {
            edgeCount++;
            mstEdges.push_back(edge);
            mstCost += edge.weight;

            addEdges(nodeIndex);
        }
    }

    if (edgeCount != m)
        return make_pair(-1, vector<WeightedEdge>());

    return make_pair(mstCost, mstEdges);
}