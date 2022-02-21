#include <bits/stdc++.h>
using namespace std;

int findMajority(vector<int> &nums)
{
    int count = 0;
    int candidate = -1;

    for (auto num : nums)
    {
        if (count == 0)
            candidate = num;

        count += candidate == num ? 1 : -1;
    }

    int majorityEleFreq = std::count(begin(nums), end(nums), candidate);
    //  count_if(begin(nums), end(nums), [&candidate](const auto &num) -> bool { return candidate == num; })

    if (majorityEleFreq < nums.size() / 2)
        throw "No majority element exists";

    return candidate;
}