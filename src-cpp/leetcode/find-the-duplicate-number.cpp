#include <bits/stdc++.h>
using namespace std;

// cycle detection
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return fast;
}

// negative marking
int findDuplicate(vector<int> &nums)
{
    int duplicate = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        int cur = abs(nums[i]);
        if (nums[cur] < 0)
        {
            duplicate = cur;
            break;
        }
        nums[cur] *= -1;
    }

    // restore numbers - optional
    for (auto &num : nums)
        num = abs(num);

    return duplicate;
}

// hash-set 1
int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> seen(n, false);

    for (auto &num : nums)
    {
        if (seen[num])
            return num;
        seen[num] = true;
    }

    return -1;
}

// hash set 2
int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> seen;

    for (auto &num : nums)
    {
        if (seen.count(num))
            return num;

        seen.insert(num);
    }

    return -1;
}

// sort
int findDuplicate(vector<int> &nums)
{
    sort(begin(nums), end(nums));
    for (int i = 1; i < nums.size(); i++)
        if (nums[i] == nums[i - 1])
            return nums[i];

    return -1;
}