#include <bits/stdc++.h>
using namespace std;

/**
 * we can divide even numbers multiple times - till we get an odd number, but we can only double odd numbers once.
 * After that, it will become an even number.
 *
 * Even numbers never increase
 *
 * we can double all odd numbers first, so we can get forget of the second operation.
 * Now, we only need to decrease the largest number - while it's even, which results a very simple solution.
 */
int minimumDeviation(vector<int> &nums)
{
    priority_queue<int> pq;
    int minNum = INT_MAX;

    for (auto num : nums)
    {
        num = num % 2 == 1 ? num * 2 : num;
        pq.push(num);
        minNum = min(minNum, num);
    }

    int res = INT_MAX;
    while (pq.top() % 2 == 0)
    {
        auto maxNum = pq.top();
        pq.pop();
        res = min(res, maxNum - minNum);
        minNum = min(minNum, maxNum / 2);
        pq.push(maxNum / 2);
    }

    return min(res, pq.top() - minNum);
}

// Heap implementation
int minimumDeviation(vector<int> &nums)
{
    int minNum = INT_MAX;
    for (auto &num : nums)
    {
        num = num % 2 == 1 ? num * 2 : num;
        minNum = min(minNum, num);
    }

    make_heap(begin(nums), end(nums));
    int res = INT_MAX;
    while (nums[0] % 2 == 0)
    {
        res = min(res, nums[0] - minNum);
        minNum = min(minNum, nums[0] / 2);

        pop_heap(begin(nums), end(nums));
        nums.back() /= 2;
        push_heap(begin(nums), end(nums));
    }

    return min(res, nums[0] - minNum);
}