#include <bits/stdc++.h>
using namespace std;

struct WeightedEdge
{
    int from;
    int to;
    int weight; // cost to reach
};

vector<int> bellmanFordShortestPath(vector<WeightedEdge> &edgeList, int numVertices, int src)
{
    vector<int> distance(numVertices, INT_MAX);
    distance[src] = 0;

    for (int i = 1; i <= numVertices; i++)
    {
        for (auto edge : edgeList)
            if (distance[edge.from] != INT_MAX)
                distance[edge.to] = min(distance[edge.to], distance[edge.from] + edge.weight);
    }

    // Check for negative cycles
    for (int i = 1; i <= numVertices; i++)
    {
        for (auto edge : edgeList)
            if (distance[edge.from] != INT_MAX && distance[edge.from] + edge.weight < distance[edge.to])
                throw "Negative Cycle Found";
    }

    return distance;
}
