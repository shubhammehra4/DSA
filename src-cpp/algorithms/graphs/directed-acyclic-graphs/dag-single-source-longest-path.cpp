#include <bits/stdc++.h>
using namespace std;

struct WeightedEdge
{
    int to;
    int weight; // cost to reach
};

vector<int> kahnTopologicalSorting(vector<vector<WeightedEdge>> &adjLists)
{
    int n = adjLists.size();
    vector<int> inDegree(n, 0);

    for (int i = 0; i < n; i++)
        for (auto edge : adjLists[i])
            inDegree[edge.to] += 1;

    queue<int> q;

    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            q.push(i);

    vector<int> ordering;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        ordering.push_back(node);

        for (auto edge : adjLists[node])
        {
            inDegree[edge.to] -= 1;

            if (inDegree[edge.to] == 0)
                q.push(edge.to);
        }
    }

    if (ordering.size() != n)
        throw "Cycle Detected";

    return ordering;
}

// NP Hard for general graph
// Liner for a DAG
vector<int> dagLongestPath(vector<vector<WeightedEdge>> &adjLists, int start)
{
    int n = adjLists.size();

    vector<vector<WeightedEdge>> modifiedAdjLists(adjLists);

    // invert the weights by -ve sign and find the shorted path
    for (auto adjList : modifiedAdjLists)
        for (auto edge : adjList)
            edge.weight = -edge.weight;

    vector<int> topSort = kahnTopologicalSorting(modifiedAdjLists);
    vector<int> distance(n, INT_MAX);
    distance[start] = 0;

    for (int i = 0; i < n; i++)
    {
        int nodeIdx = topSort[i];

        if (distance[nodeIdx] != INT_MAX)
        {
            for (auto edge : modifiedAdjLists[nodeIdx])
            {
                int newDist = distance[nodeIdx] + edge.weight;

                if (distance[edge.to] == INT_MAX)
                    distance[edge.to] = newDist;
                else
                    distance[edge.to] = min(distance[edge.to], newDist);
            }
        }
    }

    vector<int> result(n);
    transform(begin(distance), end(distance), begin(result), negate<>{});

    return result;
}