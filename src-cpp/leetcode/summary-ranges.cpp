#include <bits/stdc++.h>
using namespace std;

// group by number-index (difference)
/*
    numbers:  [0, 1, 2, 4, 5, 7]
    indexes:  [0, 1, 2, 3, 4, 5]
    subtract: [0, 0, 0, 1, 1, 2]
*/
vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> res;
    int n = nums.size();
    vector<int> numIdxDiff;
    int i = 0;
    transform(begin(nums), end(nums), back_inserter(numIdxDiff), [&i](const int &num) -> int
              { return num - i++; });

    for (int i = 0; i < n; i++)
    {
        int begin = nums[i];
        while (i < n - 1 && numIdxDiff[i] == numIdxDiff[i + 1])
            i++;
        int end = nums[i];

        if (begin == end)
            res.push_back(to_string(begin));
        else
            res.push_back(to_string(begin) + "->" + to_string(end));
    }

    return res;
}

// simple
vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> res;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int begin = nums[i];
        while (i < n - 1 && nums[i] == nums[i + 1] - 1)
            i++;
        int end = nums[i];

        if (begin == end)
            res.push_back(to_string(begin));
        else
            res.push_back(to_string(begin) + "->" + to_string(end));
    }

    return res;
}