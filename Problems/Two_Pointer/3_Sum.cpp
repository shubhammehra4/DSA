#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    int n = nums.size(), ans = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; ++i)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum3 = nums[i] + nums[l] + nums[r];
            if (sum3 == target)
                return sum3;

            if (abs(ans - target) > abs(sum3 - target))
                ans = sum3;

            if (sum3 > target)
                --r;
            else
                ++l;
        }
    }

    return ans;
}

int main()
{
    vector<int> A = {-1, 2, 1, -4};
    int B = 1;
    cout << threeSumClosest(A, B);

    return 0;
}