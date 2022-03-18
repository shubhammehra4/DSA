#include <bits/stdc++.h>
using namespace std;

// bucket-sort
int maximumGap(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return 0;

    auto lu = minmax_element(begin(nums), end(nums));

    int l = *lu.first, u = *lu.second;

    int gap = max((u - l) / (n - 1), 1);

    int m = (u - l) / gap + 1; //  no. of buckets
    vector<int> bucketsMin(m, INT_MAX);
    vector<int> bucketsMax(m, INT_MIN);

    for (int num : nums)
    {
        int k = (num - l) / gap; // bucket no.

        if (num < bucketsMin[k])
            bucketsMin[k] = num;

        if (num > bucketsMax[k])
            bucketsMax[k] = num;
    }

    int i = 0, j;
    gap = bucketsMax[0] - bucketsMin[0];

    while (i < m)
    {
        j = i + 1;
        while (j < m && bucketsMin[j] == INT_MAX && bucketsMax[j] == INT_MIN) // skip empty buckets
            j++;

        if (j == m)
            break;

        gap = max(gap, bucketsMin[j] - bucketsMax[i]);
        i = j;
    }

    return gap;
}

// brute-force heap
int maximumGap(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return 0;

    make_heap(begin(nums), end(nums));
    int gap = 0;

    while (n > 1)
    {
        int num = nums.front();
        pop_heap(begin(nums), end(nums));
        nums.pop_back();

        gap = max(gap, num - nums.front());
        n--;
    }

    return gap;
}

// brute-force sorting
int maximumGap(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return 0;

    sort(begin(nums), end(nums));
    int gap = 0;

    for (int i = 0; i < n - 1; i++)
        gap = max(gap, nums[i + 1] - nums[i]);

    return gap;
}