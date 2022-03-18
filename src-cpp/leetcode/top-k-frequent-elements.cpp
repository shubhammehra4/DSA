#include <bits/stdc++.h>
using namespace std;

// bucket
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (auto num : nums)
        ++mp[num];

    vector<vector<int>> buckets(nums.size() + 1);
    for (auto [num, freq] : mp)
        buckets[freq].push_back(num);

    reverse(begin(buckets), end(buckets));

    vector<int> res;
    for (auto &bucket : buckets)
    {
        for (auto i : bucket)
        {
            res.push_back(i);
            if (res.size() == k)
                return res;
        }
    }

    return res;
}

// hash-map and priority-queue
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    for (auto num : nums)
        mp[num]++;

    int keys = mp.size();
    vector<int> res;
    priority_queue<pair<int, int>> pq;
    for (auto [num, freq] : mp)
    {
        pq.push({freq, num});

        if (pq.size() > keys - k)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
    }

    return res;
}