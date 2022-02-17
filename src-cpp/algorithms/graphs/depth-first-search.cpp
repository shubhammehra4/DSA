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

    vector<int> depthFirstSearch(int src)
    {
        vector<bool> visited(numVertices, false);
        vector<int> parent(numVertices, -1);
        vector<int> pre(numVertices, -1);
        vector<int> post(numVertices, -1);
        int count = 0;
        vector<int> res;

        function<void(int)> dfsUtil = [&](int node) -> void
        {
            visited[node] = true;
            pre[src] = count++;
            res.push_back(node);

            for (auto neighbour : adjLists[node])
            {
                if (!visited[neighbour])
                {
                    parent[neighbour] = node;
                    dfsUtil(neighbour);
                    post[neighbour] = count++;
                }
            }
        };

        dfsUtil(src);
        post[src] = count;

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

// No. of vertices unknown
vector<int> depthFirstSearch(Node *src)
{
    unordered_map<int, bool> visited;
    vector<int> res;

    function<void(Node *)> dfsUtil = [&](Node *node) -> void
    {
        visited[node->val] = true;
        res.push_back(node->val);

        for (auto &neighbour : node->neighbors)
        {
            if (!visited[neighbour->val])
                dfsUtil(neighbour);
        }
    };

    dfsUtil(src);

    return res;
}
