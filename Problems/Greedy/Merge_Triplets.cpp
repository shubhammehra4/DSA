#include <bits/stdc++.h>
using namespace std;

bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &t)
{
    int n = triplets.size();
    int x = 0, y = 0, z = 0;

    for (auto i : triplets)
    {
        if (i[0] <= t[0] && i[1] <= t[1] && i[2] <= t[2])
        {
            x = max(x, i[0]);
            y = max(y, i[1]);
            z = max(z, i[2]);
        }
    }

    if ((x == t[0]) && (y == t[1]) && (z == t[2]))
        return true;

    return false;
}

// Shorter Version
bool mergeTriplets2(vector<vector<int>> &triplets, vector<int> &t)
{
    vector<int> res(3);
    for (auto &s : triplets)
        if (s[0] <= t[0] && s[1] <= t[1] && s[2] <= t[2])
            res = {max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2])};

    return res == t;
}

int main()
{

    return 0;
}