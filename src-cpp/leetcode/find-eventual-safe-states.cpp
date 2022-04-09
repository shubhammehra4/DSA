#include <bits/stdc++.h>
using namespace std;

// cycle-detection (white:0, gray:1, black:2)
enum COLORS
{
    WHITE,
    GRAY,
    BLACK
};
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = size(graph);
    vector<int> color(n, WHITE);
    vector<int> res;

    function<bool(int, vector<int> &)> dfs = [&graph, &dfs](int node, vector<int> &color) -> bool
    {
        if (color[node] > 0)
            return color[node] == BLACK;

        color[node] = GRAY;
        for (int child : graph[node])
        {
            if (color[node] == BLACK)
                continue;
            if (color[child] == GRAY || !dfs(child, color))
                return false;
        }
        color[node] = BLACK;

        return true;
    };

    for (int i = 0; i < n; i++)
        if (dfs(i, color))
            res.push_back(i);

    return res;
}