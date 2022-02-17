#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edge;
class Graph
{
    int numVertices;
    vector<vector<edge>> adjLists;

public:
    Graph(int vertices) : numVertices(vertices), adjLists(vector<vector<edge>>(vertices)) {}

    void addEdge(int src, int dest, int cost)
    {
        adjLists[src].push_back({cost, dest});
        adjLists[dest].push_back({cost, src});
    }

    vector<int> bestFirstSearch(int src, int target)
    {
        vector<bool> visited(numVertices, false);
        priority_queue<edge, vector<edge>, greater<edge>> pq;
        vector<int> res;

        int cost = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto node = pq.top().second;
            cost += pq.top().first;
            pq.pop();
            visited[node] = true;
            res.push_back(node);

            if (node == target)
                break;

            for (auto neighbour : adjLists[node])
            {
                if (!visited[neighbour.second])
                    pq.push(neighbour);
            }
        }

        return res;
    }
};
