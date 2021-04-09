// Top Left to Bottom Right
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll gridTravellerObstaclesDynamic (ll m, ll n, vector<vector<int>> holes)
{
    vector<vector<int>> paths (m, vector<int> (n, 0) );

    if (holes[0][n - 1] == 1) return 0;

    paths[0][n - 1] = 1; //starting

    for (int i = n - 2; i >= 0; i--)
    {
        if (holes[0][i] == 0)
            paths[0][i] = paths[0][i + 1]; // left side
    }

    for (int i = 1; i < m; i++)
    {
        if (holes[i][n - 1] == 0)
            paths[i][n - 1] = paths[i - 1][n - 1]; // top side
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (holes[i][j] == 0)
                paths[i][j] = paths[i - 1][j] + paths[i][j + 1];
        }
    }

    return paths[m - 1][0];
}

int main()
{
    ll m = 3, n = 3;
    vector<vector<int>> holes = { { 0, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 0 }
    };
    cout << gridTravellerObstaclesDynamic (m, n, holes);
    return 0;
}