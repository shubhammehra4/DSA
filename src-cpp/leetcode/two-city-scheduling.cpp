#include <bits/stdc++.h>
using namespace std;

// sorting 1
int twoCitySchedCost(vector<vector<int>> &cs, int res = 0)
{
    sort(begin(cs), end(cs),
         [](vector<int> &person1, vector<int> &person2)
         {
             int ap1 = person1[0], ap2 = person2[0];
             int bp1 = person1[1], bp2 = person2[1];

             return (ap1 + bp2 < bp1 + ap2); // p0 to A and p1 to B is cheaper than vice verse
         });

    int n = cs.size();
    for (auto i = 0; i < n / 2; ++i)
        res += cs[i][0] + cs[i + n / 2][1];

    return res;
}

// sorting 2
int twoCitySchedCost(vector<vector<int>> &costs)
{
    int res = 0;
    vector<int> refund;

    for (auto cost : costs)
    {
        res += cost[0];
        refund.push_back(cost[0] - cost[1]);
    }

    sort(begin(refund), end(refund), [](int &a, int &b)
         { return a > b; });

    int n = refund.size();
    for (int i = 0; i < n / 2; i++)
        res -= refund[i];

    return res;
}