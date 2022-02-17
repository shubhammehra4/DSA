#include <bits/stdc++.h>
using namespace std;

vector<int> centerOfTree(vector<vector<int>> &adjLists)
{
    int n = adjLists.size();
    vector<int> degree(n, 0);
    vector<int> leaves;

    for (int i = 0; i < n; i++)
    {
        degree[i] = adjLists[i].size();
        if (degree[i] == 0 || degree[i] == 1)
        {
            leaves.push_back(i);
            degree[i] = 0;
        }
    }

    int prunedNodes = leaves.size();

    while (prunedNodes < n)
    {
        vector<int> newLeaves;
        for (auto node : leaves)
        {
            for (auto neighbor : adjLists[node])
            {
                degree[neighbor]--;
                if (degree[neighbor] == 1)
                    newLeaves.push_back(neighbor);
            }
            degree[node] = 0;
        }
        prunedNodes += newLeaves.size();
        leaves = newLeaves;
    }

    return leaves; // center(s)
}