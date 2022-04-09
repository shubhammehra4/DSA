#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
{
    int n = firstList.size();
    int m = secondList.size();
    vector<vector<int>> res;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        auto low = max(firstList[i][0], secondList[j][0]);
        auto high = min(firstList[i][1], secondList[j][1]);

        if (low <= high)
            res.push_back({low, high});

        if (firstList[i][1] < secondList[j][1])
            i++;
        else
            j++;
    }

    return res;
}