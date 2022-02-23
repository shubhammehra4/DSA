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

vector<int> bestFirstSearch(vector<vector<WeightedEdge>> &adjLists, int src, int target)
{
    int n = adjLists.size();
    vector<bool> visited(n, false);
    priority_queue<WeightedEdge, vector<WeightedEdge>, decltype(comparator)> pq(comparator);
    vector<int> pathRes;

    int cost = 0;
    pq.push({src, 0});

    while (!pq.empty())
    {
        auto edge = pq.top();
        pq.pop();

        cost += edge.weight;
        visited[edge.to] = true;

        pathRes.push_back(edge.to);

        if (edge.to == target)
            break;

        for (auto neighbour : adjLists[edge.to])
            if (!visited[neighbour.to])
                pq.push(neighbour);
    }

    return pathRes;
}
