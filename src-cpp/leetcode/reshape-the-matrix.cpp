#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    int m = mat.size(), n = mat[0].size();
    int total = m * n;

    if (r * c != total)
        return mat;

    vector<vector<int>> res(r, vector<int>(c));
    int _r = 0, _c = 0;

    for (auto &row : mat)
        for (auto el : row)
        {
            res[_r][_c++] = el;

            if (_c == c)
                _c = 0, _r++;
        }

    return res;
}

// Alter
vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    int m = size(mat), n = size(mat[0]);
    int total = m * n;

    if (r * c != total)
        return mat;

    vector<vector<int>> ans(r, vector<int>(c));
    for (int i = 0; i < total; i++)
        ans[i / c][i % c] = mat[i / n][i % n];

    return ans;
}
