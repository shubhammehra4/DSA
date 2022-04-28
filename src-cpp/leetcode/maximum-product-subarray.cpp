#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int best = INT_MIN;
    int maxProd = 1;
    int minProd = 1;

    for (int num : nums)
    {
        if (num < 0)
            swap(maxProd, minProd);

        maxProd = max(maxProd * num, num);
        minProd = min(minProd * num, num);

        best = max(best, maxProd);
    }

    return best;
}