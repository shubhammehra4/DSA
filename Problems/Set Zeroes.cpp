#include <bits/stdc++.h>
using namespace  std;

void setZeroes (vector<vector<int> > &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    bool hasZeroFirstRow = false, hasZeroFirstColumn = false;

    for (int j = 0; j < m; ++j)
    {
        if (matrix[0][j] == 0)
        {
            hasZeroFirstRow = true;
            break;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (matrix[i][0] == 0)
        {
            hasZeroFirstColumn = true;
            break;
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
        }
    }

    if (hasZeroFirstRow)
    {
        for (int j = 0; j < m; ++j)
            matrix[0][j] = 0;
    }

    if (hasZeroFirstColumn)
    {
        for (int i = 0; i < n; ++i)
            matrix[i][0] = 0;
    }
}


int main ()
{
    return 0;
}
