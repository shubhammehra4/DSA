#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> arr)
{
    if (arr.size() == 0)
        return {};

    vector<int> res;
    int row = 0, n = arr.size() - 1;
    int col = 0, m = arr[0].size() - 1;
    int dir = 0;

    while (row <= n && col <= m)
    {
        if (dir == 0)
        {
            for (int i = col; i <= m; i++)
                res.push_back(arr[row][i]);

            row++;
        }
        else if (dir == 1)
        {
            for (int i = row; i <= n; i++)
                res.push_back(arr[i][m]);

            m--;
        }
        else if (dir == 2)
        {
            for (int i = m; i >= col; i--)
                res.push_back(arr[n][i]);

            n--;
        }
        else if (dir == 3)
        {
            for (int i = n; i >= row; i--)
                res.push_back(arr[i][col]);

            col++;
        }

        dir = (dir + 1) % 4;
    }

    return res;
}
