#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &g, vector<vector<int>> &res, vector<int> &path, int node)
{
    path.push_back(node);

    if (node == g.size() - 1)
        res.push_back(path);
    else
    {
        for (auto child : g[node])
            dfs(g, res, path, child);
    }

    path.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> paths;
    vector<int> path;
    dfs(graph, paths, path, 0);
    return paths;
}