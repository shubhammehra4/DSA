#include <bits/stdc++.h>
using namespace std;

int maxNonOverlapping(vector<int> &nums, int target)
{
    unordered_map<int, int> mp; // value, index
    mp[0] = -1;
    int sum = 0;    // running sum
    int right = -1; // end of prev sub-arr
    int cnt = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];
        if (mp.count(sum - target))
        {
            int left = mp[sum - target];
            if (right <= left)
            {
                ++cnt;
                right = i;
            }
        }

        mp[sum] = i;
    }

    return cnt;
}