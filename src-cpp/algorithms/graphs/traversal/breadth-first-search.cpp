#include <bits/stdc++.h>
using namespace std;

vector<int> breadthFirstSearch(vector<vector<int>> &adjLists, int src)
{
    int n = adjLists.size();
    vector<bool> visited(n, false);
    vector<int> traversalRes;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        visited[node] = true;
        traversalRes.push_back(node);

        for (auto neighbour : adjLists[node])
        {
            if (!visited[neighbour])
                q.push(neighbour);
        }
    }

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

vector<int> breadthFirstSearch(Node *src)
{
    unordered_map<int, bool> visited;
    vector<int> traversalRes;

    queue<Node *> q;
    q.push(src);

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        traversalRes.push_back(node->val);
        visited[node->val] = true;

        for (auto neighbour : node->neighbors)
        {
            if (!visited[neighbour->val])
                q.push(neighbour);
        }
    }

    return traversalRes;
}