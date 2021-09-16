#include <bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(vector<int> &nums)
{
    int n = size(nums), cur_sum = 0, ans = 0;
    unordered_set<int> s;
    int left = 0;

    for (int i = 0; i < n; i++)
    {
        // Delete all elements till the duplicate element and update the sum
        while (s.find(nums[i]) != end(s))
        {
            cur_sum -= nums[left];
            s.erase(nums[left++]);
        }

        cur_sum += nums[i];
        s.insert(nums[i]);
        ans = max(ans, cur_sum);
    }

    return ans;
}

int main()
{
    return 0;
}