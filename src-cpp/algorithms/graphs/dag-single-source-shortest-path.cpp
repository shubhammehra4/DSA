#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int dest;
    int weight;
};

vector<int> kahnTopologicalSorting(vector<vector<edge>> &adjLists)
{
    int n = adjLists.size();
    vector<int> inDegree(n, 0);

    for (int i = 0; i < n; i++)
        for (auto edge : adjLists[i])
            inDegree[edge.dest] += 1;

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
            inDegree[edge.dest] -= 1;

            if (inDegree[edge.dest] == 0)
                q.push(edge.dest);
        }
    }

    if (ordering.size() != n)
        throw "Cycle Detected";

    return ordering;
}

vector<int> dagShortestPath(vector<vector<edge>> &adjLists, int start)
{
    int n = adjLists.size();
    vector<int> topSort = kahnTopologicalSorting(adjLists);
    vector<int> distance(n, INT_MAX);
    distance[start] = 0;

    for (int i = 0; i < n; i++)
    {
        int nodeIdx = topSort[i];

        if (distance[nodeIdx] != INT_MAX)
        {
            for (auto edge : adjLists[nodeIdx])
            {
                int newDist = distance[nodeIdx] + edge.weight;

                if (distance[edge.dest] == INT_MAX)
                    distance[edge.dest] = newDist;
                else
                    distance[edge.dest] = min(distance[edge.dest], newDist);
            }
        }
    }

    return distance;
}