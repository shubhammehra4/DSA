#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edge;
class Graph
{
    int numVertices;
    vector<vector<edge>> adjLists;

public:
    Graph(int vertices) : numVertices(vertices), adjLists(vector<vector<edge>>(vertices)) {}

    vector<int> dijkstrasShortestPath(int src, int target)
    {
        priority_queue<edge, vector<edge>, greater<edge>> pq;
        vector<bool> visited(numVertices, false);
        vector<int> distance(numVertices, INT_MAX);
        vector<int> path;
        int pathCost = 0;

        pq.push({0, src});
        distance[src] = 0;

        while (!pq.empty())
        {
            auto cost = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            visited[node] = true;
            pathCost += cost;
            path.push_back(node);

            if (distance[node] < cost)
                continue;

            for (auto neighbour : adjLists[node])
            {
                auto nextNodeCost = neighbour.first;
                auto nextNode = neighbour.second;

                if (!visited[nextNode] && distance[nextNode] > distance[node] + nextNodeCost)
                {
                    distance[nextNode] = distance[node] + nextNodeCost;
                    pq.push({distance[nextNode], nextNode});
                }
            }

            if (node == target)
                break;
        }

        return path;
    }
};
