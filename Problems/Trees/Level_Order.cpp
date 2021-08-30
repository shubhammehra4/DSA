#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    if (root == NULL)
        return {};

    vector<vector<int>> res;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> currlevel;
        for (int i = 0; i < q.size(); i++)
        {
            Node *tmp = q.front();
            q.pop();
            currlevel.push_back(tmp->val);
            for (auto n : tmp->children)
                q.push(n);
        }
        res.push_back(currlevel);
    }
    return res;
}

int main()
{
    return 0;
}