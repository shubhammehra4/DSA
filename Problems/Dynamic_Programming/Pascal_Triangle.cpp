#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ret;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
        ret.push_back(row);
    }
    return ret;
}

// Can be done effeciently using the formula
vector<int> getRow(int rowIndex)
{
    vector<vector<int>> ret;
    for (int i = 0; i < rowIndex; i++)
    {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
        ret.push_back(row);
    }
    return ret[rowIndex - 1];
}

int main()
{
    return 0;
}