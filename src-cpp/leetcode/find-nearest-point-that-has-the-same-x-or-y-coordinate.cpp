#include <bits/stdc++.h>
using namespace std;

#define manhattanDistance(x1, y1, x2, y2) abs(x1 - x2) + abs(y1 - y2)

// [[gnu::pure]] int manhattanDistance(int x1, int y1, int x2, int y2)
// {
//     return abs(x1 - x2) + abs(y1 - y2);
// }

int nearestValidPoint(int x, int y, vector<vector<int>> &points)
{
    int dist = INT_MAX;
    int res = -1;

    for (int i = 0; i < points.size(); i++)
    {
        if (points[i][0] == x || points[i][1] == y)
        {
            int mnDist = manhattanDistance(x, y, points[i][0], points[i][1]);
            if (dist > mnDist)
            {
                dist = mnDist;
                res = i;
            }
        }
    }

    return res;
}
