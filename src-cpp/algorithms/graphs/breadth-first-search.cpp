#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int numVertices;
    vector<vector<int>> adjLists;

public:
    Graph(int vertices) : numVertices(vertices), adjLists(vector<vector<int>>(vertices)) {}

    void addEdge(int src, int dest)
    {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    vector<int> breadthFirstSearch(int src)
    {
        vector<bool> visited(numVertices, false);
        vector<int> res;

        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            visited[node] = true;
            res.push_back(node);

            for (auto neighbour : adjLists[node])
            {
                if (!visited[neighbour])
                    q.push(neighbour);
            }
        }

        return res;
    }
};

// Alternative
struct Node
{
    int val;
    vector<Node *> neighbors;
    Node() : val(0), neighbors(vector<Node *>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node *>()) {}
    Node(int _val, vector<Node *> _neighbours) : val(_val), neighbors(vector<Node *>(_neighbours)) {}
};

vector<int> breadthFirstSearch(Node *src)
{
    unordered_map<int, bool> visited;
    vector<int> res;

    queue<Node *> q;
    q.push(src);

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        res.push_back(node->val);
        visited[node->val] = true;

        for (auto neighbour : node->neighbors)
        {
            if (!visited[neighbour->val])
                q.push(neighbour);
        }
    }
    return res;
}