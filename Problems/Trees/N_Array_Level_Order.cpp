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
    vector<vector<int>> ans;
    if (!root)
        return ans;

    queue<Node *> q;
    q.push(root);
    vector<int> temp = {root->val};
    ans.push_back(temp);
    while (!q.empty())
    {
        temp.clear();
        int nodes = q.size();
        while (nodes--)
        {
            Node *curr = q.front();
            q.pop();
            for (auto node : curr->children)
            {
                temp.push_back(node->val);
                q.push(node);
            }
        }
        if (temp.empty())
            continue;

        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    return 0;
}