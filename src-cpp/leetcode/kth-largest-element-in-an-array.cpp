#include <bits/stdc++.h>
using namespace std;

// stl-1
int findKthLargest(vector<int> &nums, int k)
{
    nth_element(begin(nums), begin(nums) + k - 1, end(nums), greater<int>());
    return nums[k - 1];
}

// stl-2
int findKthLargest(vector<int> &nums, int k)
{
    partial_sort(begin(nums), begin(nums) + k, end(nums), greater<int>());
    return nums[k - 1];
}

// heap using priority-queue
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto num : nums)
    {
        pq.push(num);
        if (pq.size() > k)
            pq.pop();
    }

    return pq.top();
}

// heap using priority-queue - 2
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> pq(begin(nums), end(nums));

    for (int i = 0; i < k - 1; i++)
        pq.pop();

    return pq.top();
}

// using heap
int findKthLargest(vector<int> &nums, int k)
{
    make_heap(begin(nums), end(nums));

    int n = k - 1;
    while (n--)
    {
        pop_heap(begin(nums), end(nums));
        nums.pop_back();
    }

    return nums.front();
}

// brute-force
int findKthLargest(vector<int> &nums, int k)
{
    sort(begin(nums), end(nums));

    return nums[nums.size() - k - 1];
}