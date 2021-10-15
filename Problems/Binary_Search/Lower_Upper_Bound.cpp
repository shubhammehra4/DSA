#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &a, int target)
{
    int l = 0, r = a.size() - 1;
    int res = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (a[m] < target)
            l = m + 1;
        else if (a[m] > target)
            r = m - 1;
        else
        {
            if (m == l || a[m] != a[m - 1])
            {
                res = m;
                break;
            }
            else
            {
                r = m - 1;
                res = m - 1;
            }
        }
    }
    return res;
}

int upperBound(vector<int> &a, int target)
{
    int l = 0, r = a.size() - 1;
    int res = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a[m] < target)
            l = m + 1;
        else if (a[m] > target)
            r = m - 1;
        else
        {
            if (m == r || a[m] != a[m + 1])
            {
                res = m;
                break;
            }
            else
            {
                l = m + 1;
                res = m + 1;
            }
        }
    }
    return res;
}

vector<int> searchRange(vector<int> &a, int target)
{
    int l = 0, r = a.size() - 1;
    vector<int> ans(2, -1);
    ans[0] = lowerBound(a, target);
    ans[1] = upperBound(a, target);

    return ans;
}