#include <bits/stdc++.h>
using namespace std;

// bfs
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    vector<bool> visited(n, false);

    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        auto room = q.front();
        q.pop();
        visited[room] = true;

        for (auto key : rooms[room])
            if (!visited[key])
                q.push(key);
    }

    return all_of(begin(visited), end(visited), [](bool room)
                  { return room; });
}

// dfs and set
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    stack<int> dfs;
    dfs.push(0);

    unordered_set<int> seen = {0};
    while (!dfs.empty())
    {
        int room = dfs.top();
        dfs.pop();

        for (int key : rooms[room])
            if (seen.count(key) == 0)
            {
                dfs.push(key);
                seen.insert(key);
                if (rooms.size() == seen.size())
                    return true;
            }
    }
    return rooms.size() == seen.size();
}
