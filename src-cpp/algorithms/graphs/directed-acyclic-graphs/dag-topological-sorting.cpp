#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int node, vector<int> &visited, vector<int> &ordering, vector<vector<int>> &adjLists)
{
    visited[node] = true;
    for (auto neighbor : adjLists[node])
        if (!visited[neighbor])
            i = dfs(i, neighbor, visited, ordering, adjLists);

    return i - 1;
}

vector<int> topologicalSort(vector<vector<int>> &adjLists)
{
    int n = adjLists.size();
    vector<int> visited(n, false);
    vector<int> ordering(n); // ordering can be converted into a stack, instead of using orderIdx
    int orderIdx = n - 1;

    for (int id = 0; id < n; id++)
    {
        if (!visited[id])
            orderIdx = dfs(orderIdx, id, visited, ordering, adjLists);
    }

    return ordering;
}

// Alternative
// Not Optimised

// void dfs(int node, vector<int> &visited, vector<int> &visitedNodes, vector<vector<int>> &adjLists)
// {
//     visited[node] = true;

//     for (auto neighbor : adjLists[node])
//     {
//         if (!visited[neighbor])
//             dfs(neighbor, visited, visitedNodes, adjLists);
//     }

//     visitedNodes.push_back(node);
// }

// vector<int> topologicalSort(vector<vector<int>> &adjLists)
// {
//     int n = adjLists.size();
//     vector<int> visited(n, false);
//     vector<int> ordering(n);
//     int orderIdx = n - 1;

//     for (int id = 0; id < n; id++)
//     {
//         if (!visited[id])
//         {
//             vector<int> visitedNodes;
//             dfs(id, visited, visitedNodes, adjLists);

//             for (auto nodeId : visitedNodes)
//             {
//                 ordering[orderIdx] = nodeId;
//                 orderIdx--;
//             }
//         }
//     }

//     return ordering;
// }
