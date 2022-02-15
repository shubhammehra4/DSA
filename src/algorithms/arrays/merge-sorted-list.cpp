#include <bits/stdc++.h>
using namespace std;

// 2 way merging
vector<int> merge(vector<int> &v1, vector<int> &v2)
{
    int n = v1.size();
    int m = v2.size();
    int i = 0, j = 0;
    vector<int> mergedRes;

    while (i < n && j < m)
    {
        if (v1[i] <= v2[j])
        {
            mergedRes.push_back(v1[i]);
            i++;
        }
        else
        {
            mergedRes.push_back(v2[j]);
            j++;
        }
    }

    for (; i < n; i++)
        mergedRes.push_back(v1[i]);

    for (; j < m; j++)
        mergedRes.push_back(v2[j]);

    return mergedRes;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 9, 10};
    vector<int> b = {-1, 3, 6, 7, 8, 9, 12};

    vector<int> c = merge(a, b);

    for (auto &i : c)
        cout << i << " ";

    return 0;
}