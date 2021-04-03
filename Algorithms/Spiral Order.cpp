#include <bits/stdc++.h>
using namespace std;

vector<int> spiralTraversal (vector<vector<int> >v)
{
    vector<int> res;

    if (v.size() == 0) return res;

    int t = 0, d = v.size() - 1, l = 0, r = v[0].size() - 1;
    int dir = 0;

    while (t <= d && l <= r)
    {
        if (dir == 0)
        {
            for (int i = l; i <= r; i++)
                res.push_back (v[t][i]);

            t++;
        }
        else if (dir == 1)
        {
            for (int i = t; i <= d; i++ )
                res.push_back (v[i][r]);

            r--;
        }
        else if (dir == 2)
        {
            for (int i = r; i >= l; i--)
                res.push_back (v[d][i]);

            d--;
        }
        else if (dir == 3)
        {
            for (int i = d; i >= t; i-- )
                res.push_back (v[i][l]);

            l++;
        }

        dir = (dir + 1) % 4;
    }

    return res;
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = spiralTraversal (v);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
