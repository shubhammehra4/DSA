#include <bits/stdc++.h>
using namespace std;

int countElements(vector<int> &nums)
{
    int maxNum = *max_element(begin(nums), end(nums));
    int minNum = *min_element(begin(nums), end(nums));

    if (maxNum == minNum)
        return 0;

    int res = 0;
    for (auto num : nums)
    {
        if (num > minNum && num < maxNum)
            res++;
    }

    return res;
}

// Alter
int countElements(vector<int> &n)
{
    const auto mm = minmax_element(begin(n), end(n));

    return count_if(begin(n), end(n), [&](int n)
                    { return n > *mm.first && n < *mm.second; });
}