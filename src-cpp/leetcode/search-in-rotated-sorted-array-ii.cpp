#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int n = nums.size();

    if (n == 0)
        return false;

    int start = 0;
    int end = n - 1;

    auto existsInFirst = [&nums](int start, int num) -> bool
    {
        return nums[start] <= num;
    };

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return true;

        if (nums[start] == nums[mid])
        {
            start++;
            continue;
        }

        bool pivotArray = existsInFirst(start, nums[mid]);
        bool targetArray = existsInFirst(start, target);

        if (pivotArray ^ targetArray) // both distinct
        {
            if (pivotArray)
                start = mid + 1; // pivot in the first, target in the second
            else
                end = mid - 1; // target in the first, pivot in the second
        }
        else
        {
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return false;
}
