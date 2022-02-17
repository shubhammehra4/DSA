#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, vector<int>> valueIndices;

    for (int i = 0; i < n; i++)
        valueIndices[arr[i]].push_back(i);

    vector<bool> visited(n, false);
    queue<int> q;
    int jumps = 0;

    visited[0] = true;
    q.push(0);
    while (!q.empty())
    {
        for (int size = q.size(); size > 0; --size)
        {
            int i = q.front();
            q.pop();
            if (i == n - 1)
                return jumps; // Reached to last index

            auto &next = valueIndices[arr[i]];
            next.push_back(i - 1);
            next.push_back(i + 1);

            for (auto j : next)
            {
                if (j >= 0 && j < n && !visited[j])
                {
                    visited[j] = true;
                    q.push(j);
                }
            }
            next.clear();
        }
        jumps++;
    }

    return 0;
}