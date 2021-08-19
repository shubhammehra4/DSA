#include <bits/stdc++.h>
using namespace std;

// Bucket Sort O(n)
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> counts;
    for (auto i : nums)
        ++counts[i];

    vector<vector<int>> buckets(nums.size() + 1);
    for (auto k : counts)
        buckets[k.second].push_back(k.first);

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

// Min Heap O(n * log(n-k))
vector<int> topKFrequent2(vector<int> &nums, int k)
{
    unordered_map<int, int> counts;
    priority_queue<int, vector<int>, greater<int>> max_k;
    for (auto i : nums)
        ++counts[i];

    for (auto &i : counts)
    {
        max_k.push(i.second);
        while (max_k.size() > k)
            max_k.pop();
    }

    vector<int> res;
    for (auto &i : counts)
        if (i.second >= max_k.top())
            res.push_back(i.first);

    return res;
}

int main()
{

    return 0;
}