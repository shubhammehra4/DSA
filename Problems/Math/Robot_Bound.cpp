#include <bits/stdc++.h>
using namespace std;

bool isRobotBounded(string instructions)
{
    int x = 0, y = 0, i = 0;
    vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // N E S W

    for (char &ins : instructions)
    {
        if (ins == 'R')
            i = (i + 1) % 4;
        else if (ins == 'L')
            i = (i + 3) % 4;
        else
            x += d[i][0], y += d[i][1];
    }
    // if at origin or not facing north
    return (x == 0 && y == 0) || i > 0;
}

int main()
{

    return 0;
}