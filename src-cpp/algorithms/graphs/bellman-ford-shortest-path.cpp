#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int src, dest, weight;
};
class Graph
{
    int numVertices;
    int numEdges;
    vector<edge> edgeList;

public:
    Graph(int vertices, int edges) : numVertices(vertices), numEdges(edges), edgeList(vector<edge>()) {}

    vector<int> bellmanFordShortestPath(int src)
    {
        vector<int> distance(numVertices, INT_MAX);
        distance[src] = 0;

        for (int i = 1; i <= numVertices; i++)
        {
            for (int j = 0; j < numEdges; j++)
            {
                auto edge = edgeList[j];

                if (distance[edge.src] != INT_MAX)
                    distance[edge.dest] = min(distance[edge.dest], distance[edge.src] + edge.weight);
            }
        }

        // Check for negative cycles
        for (int i = 1; i <= numVertices; i++)
        {
            for (int j = 0; j < numEdges; j++)
            {
                auto edge = edgeList[j];

                if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.dest])
                    throw "Negative Cycle Found";
            }
        }

        return distance;
    }
};
