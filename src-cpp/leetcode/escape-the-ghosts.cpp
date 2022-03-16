#include <bits/stdc++.h>
using namespace std;

bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &t)
{
    int d = abs(t[0]) + abs(t[1]);

    for (auto g : ghosts)
        if (d >= abs(t[0] - g[0]) + abs(t[1] - g[1]))
            return false;

    return true;
}