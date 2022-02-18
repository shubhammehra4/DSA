#include <bits/stdc++.h>
using namespace std;

// dfs
int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    vector<vector<int>> children(n, vector<int>());

    for (int employeId = 0; employeId < n; employeId++)
        if (manager[employeId] != -1)
            children[manager[employeId]].push_back(employeId);

    function<int(int)> dfs = [&children, &informTime, &dfs](int node) -> int
    {
        int time = 0;
        for (auto &child : children[node])
            time = max(time, dfs(child));

        return informTime[node] + time;
    };

    return dfs(headID);
}

// bfs
int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    vector<vector<int>> children(n, vector<int>());

    for (int employeId = 0; employeId < n; employeId++)
        if (manager[employeId] != -1)
            children[manager[employeId]].push_back(employeId);

    queue<pair<int, int>> q;
    q.push({headID, 0});
    int maxDuration = 0;

    while (!q.empty())
    {
        int levelSize = q.size();

        while (levelSize--)
        {
            auto node = q.front();
            q.pop();
            int duration = node.second + informTime[node.first];
            maxDuration = max(maxDuration, duration);

            for (auto child : children[node.first])
                q.push({child, duration});
        }
    }

    return maxDuration;
}