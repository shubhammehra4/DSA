#include <bits/stdc++.h>
using namespace std;

// @refer - k-sum for general solution

// sort 2-ptr 2-sum
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    if (nums.empty())
        return res;

    int n = size(nums);
    sort(begin(nums), end(nums));

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int t = target - nums[i] - nums[j];
            int l = j + 1;
            int r = n - 1;

            while (l < r)
            {
                int sum = nums[l] + nums[r];

                if (sum < t)
                    l++;
                else if (sum > t)
                    r--;
                else
                {
                    vector<int> quadruplet{nums[i], nums[j], nums[l], nums[r]};
                    res.push_back(quadruplet);

                    // Processing the duplicates of number 3
                    while (l < r && nums[l] == quadruplet[2])
                        ++l;

                    // Processing the duplicates of number 4
                    while (l < r && nums[r] == quadruplet[3])
                        --r;
                }
            }
            // Processing the duplicates of number 2
            while (j + 1 < n && nums[j + 1] == nums[j])
                ++j;
        }
        // Processing the duplicates of number 1
        while (i + 1 < n && nums[i + 1] == nums[i])
            ++i;
    }

    return res;
}

// sort 3-ptr binary-search
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = size(nums);
    sort(begin(nums), end(nums));
    set<vector<int>> sv;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int x = (long long)target -
                        (long long)nums[i] -
                        (long long)nums[j] - (long long)nums[k];

                if (binary_search(begin(nums) + k + 1, end(nums), x))
                {
                    vector<int> v{nums[i], nums[j], nums[k], x};
                    sort(begin(v), end(v));
                    sv.insert(v);
                }
            }
        }
    }
    vector<vector<int>> res(begin(sv), end(sv));
    return res;
}
