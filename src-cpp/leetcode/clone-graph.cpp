#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    vector<Node *> neighbors;
    Node() : val(0), neighbors(vector<Node *>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node *>()) {}
    Node(int _val, vector<Node *> _neighbours) : val(_val), neighbors(vector<Node *>(_neighbours)) {}
};

unordered_map<Node *, Node *> copies;

Node *cloneGraph(Node *node)
{
    if (!node)
        return nullptr;

    auto copy = new Node(node->val, {});

    copies[node] = copy;
    queue<Node *> todo;
    todo.push(node);

    while (!todo.empty())
    {
        auto cur = todo.front();
        todo.pop();

        for (auto neighbor : cur->neighbors)
        {
            if (copies.find(neighbor) == copies.end())
            {
                copies[neighbor] = new Node(neighbor->val, {});
                todo.push(neighbor);
            }

            copies[cur]->neighbors.push_back(copies[neighbor]);
        }
    }

    return copy;
}

// DFS
Node *cloneGraph(Node *node)
{
    if (!node)
        return nullptr;

    if (copies.find(node) == copies.end())
    {
        copies[node] = new Node(node->val, {});
        for (auto neighbor : node->neighbors)
            copies[node]->neighbors.push_back(cloneGraph(neighbor));
    }

    return copies[node];
}