#include <bits/stdc++.h>
using namespace std;

// buckets
bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    int n = nums.size();
    if (n == 0 || k < 0 || t < 0)
        return false;

    unordered_map<int, int> buckets;
    for (int i = 0; i < n; ++i)
    {
        int bucket = nums[i] / ((long)t + 1); // bucket no.
        // For negative numbers, we need to decrement bucket by 1
        // For example, -1/2 = 0 but -1 should be put in Bucket[-1].
        if (nums[i] < 0)
            --bucket;

        // check same bucket
        if (buckets.find(bucket) != buckets.end())
            return true;

        buckets[bucket] = nums[i];

        // check nighbouring buckets
        if (buckets.count(bucket - 1) && (long)nums[i] - buckets[bucket - 1] <= t)
            return true;

        // check nighbouring buckets
        if (buckets.count(bucket + 1) && (long)buckets[bucket + 1] - nums[i] <= t)
            return true;

        if (buckets.size() > k)
        {
            int bucket_to_remove = nums[i - k] / ((long)t + 1); // bucket no.

            if (nums[i - k] < 0)
                --bucket_to_remove;

            buckets.erase(bucket_to_remove);
        }
    }

    return false;
}

// brute-force
bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= min(n - 1, i + k); j++)
        {
            if (abs((long long)nums[i] - (long long)nums[j]) <= (long long)t)
                return true;
        }

    return false;
}