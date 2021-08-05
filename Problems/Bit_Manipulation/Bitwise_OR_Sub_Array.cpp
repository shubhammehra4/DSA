#include <bits/stdc++.h>
using namespace std;

int subarrayBitwiseORs(vector<int> &arr)
{
    set<int> sec, dp_set;
    dp_set.insert(0);
    for (int i = 0; i < arr.size(); i++)
    {
        set<int> temp;
        temp.insert(arr[i]);
        for (auto n : dp_set)
            temp.insert(arr[i] | n);

        dp_set = temp;
        sec.insert(dp_set.begin(), dp_set.end());
    }

    return sec.size();
}

// Two Pointer Approach
int subarrayBitwiseORs(vector<int> A)
{
    vector<int> res;
    int left = 0, right;

    for (int a : A)
    {
        right = res.size();
        res.push_back(a);

        for (int i = left; i < right; i++)
            if (res.back() != (res[i] | a))
                res.push_back(res[i] | a);

        left = right;
    }

    return set<int>(res.begin(), res.end()).size();
}

int main()
{
    return 0;
}