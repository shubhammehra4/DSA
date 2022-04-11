#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int l = 0;
    int r = numbers.size() - 1;

    while (l < r)
    {
        if (numbers[l] + numbers[r] == target)
            return {l + 1, r + 1};

        if (numbers[l] + numbers[r] > target)
            r--;
        else
            l++;
    }

    return {};
}