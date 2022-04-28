#include <bits/stdc++.h>
using namespace std;

// hash-set
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> hashSet(begin(nums), end(nums));
    int streak = 0;

    for (int num : nums)
    {
        if (!hashSet.count(num - 1))
        {
            int currNum = num;
            int currStreak = 1;

            while (hashSet.count(currNum + 1))
            {
                currNum += 1;
                currStreak += 1;
            }

            streak = max(streak, currStreak);
        }
    }

    return streak;
}

// sorting
int longestConsecutive(vector<int> nums)
{
    sort(begin(nums), end(nums));
    int streak = 1;
    int currStreak = 1;

    int prev = nums[0];
    for (int i = 1; i < size(nums); i++)
    {
        if (nums[i] == prev + 1)
            currStreak++;
        else if (nums[i] != prev) // duplicates
            currStreak = 1;

        prev = nums[i];
        streak = max(streak, currStreak);
    }

    return streak;
}