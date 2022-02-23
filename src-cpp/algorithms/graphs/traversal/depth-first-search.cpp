#include <bits/stdc++.h>
using namespace std;

vector<int> depthFirstSearch(vector<vector<int>> &adjLists, int src)
{
    int n = adjLists.size();

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<int> pre(n, -1);
    vector<int> post(n, -1);
    int count = 0;
    vector<int> traversalRes;

    function<void(int)> dfsUtil = [&](int node) -> void
    {
        visited[node] = true;
        pre[src] = count++;
        traversalRes.push_back(node);

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

    return traversalRes;
}

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
    vector<int> traversalRes;

    function<void(Node *)> dfsUtil = [&](Node *node) -> void
    {
        visited[node->val] = true;
        traversalRes.push_back(node->val);

        for (auto &neighbour : node->neighbors)
        {
            if (!visited[neighbour->val])
                dfsUtil(neighbour);
        }
    };

    dfsUtil(src);

    return traversalRes;
}
