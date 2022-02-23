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

vector<int> dijkstrasShortestPath(vector<vector<WeightedEdge>> &adjLists, int src, int target)
{
    int n = adjLists.size();

    priority_queue<WeightedEdge, vector<WeightedEdge>, decltype(comparator)> pq(comparator);
    vector<bool> visited(n, false);
    vector<int> distance(n, INT_MAX);
    vector<int> path;
    int pathCost = 0;

    pq.push({src, 0});
    distance[src] = 0;

    while (!pq.empty())
    {
        auto edge = pq.top();
        pq.pop();

        visited[edge.to] = true;
        pathCost += edge.weight;
        path.push_back(edge.to);

        if (distance[edge.to] < edge.weight)
            continue;

        for (auto neighbour : adjLists[edge.to])
        {
            if (!visited[neighbour.to] && distance[neighbour.to] > distance[edge.to] + edge.weight)
            {
                distance[neighbour.to] = distance[edge.to] + edge.weight;
                pq.push({neighbour.to, distance[neighbour.to]});
            }
        }

        if (edge.to == target)
            break;
    }

    return path;
}
