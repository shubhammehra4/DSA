#include <bits/stdc++.h>
using namespace std;

vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
{
    unordered_map<string, int> mp;

    for (int i = 0; i < list1.size(); i++)
        mp[list1[i]] = i;

    int idxSum = INT_MAX;
    vector<string> res;

    for (int i = 0; i < list2.size(); i++)
    {
        if (mp.find(list2[i]) != mp.end())
        {
            int newIdxSum = i + mp[list2[i]];
            if (newIdxSum < idxSum)
            {
                idxSum = newIdxSum;
                res.clear();
                res.push_back(list2[i]);
            }
            else if (newIdxSum == idxSum)
                res.push_back(list2[i]);
        }
    }

    return res;
}