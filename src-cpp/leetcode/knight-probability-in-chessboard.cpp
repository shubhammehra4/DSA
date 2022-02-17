#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1},
    {2, 1},
    {1, 2},
    {-1, 2},
    {-2, 1},
};

double knightProbability(int n, int k, int row, int column)
{
    vector<vector<double>> probBoard(n, vector<double>(n, 1));
    vector<vector<double>> nextProbBoard(n, vector<double>(n, 0));

    auto isOutOfBound = [n](int i, int j) -> bool
    {
        return i < 0 || j < 0 || i >= n || j >= n;
    };

    for (int step = 1; step <= k; step++)
    {
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                double prob = 0;
                for (auto next : directions)
                {
                    int nextR = r + next.first;
                    int nextC = c + next.second;

                    if (!isOutOfBound(nextR, nextC))
                        prob += probBoard[nextR][nextC];
                }
                nextProbBoard[r][c] = prob / 8;
            }
        }

        swap(nextProbBoard, probBoard);
    }

    return probBoard[row][column];
}