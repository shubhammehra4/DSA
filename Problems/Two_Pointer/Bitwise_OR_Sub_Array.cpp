#include <bits/stdc++.h>
using namespace std;

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