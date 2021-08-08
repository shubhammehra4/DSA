// Longest Subarray of 1's After Deleting One Element
#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int c = 1;
    int i = 0, j = 0;
    int maxm = INT_MIN;

    while (j < nums.size())
    {
        if (nums[j] == 0)
            --c;

        if (c >= 0)
            maxm = max(maxm, j - i);
        else if (c < 0)
        {
            while (c < 0)
            {
                if (nums[i] == 0)
                    ++c;
                ++i;
            }
            maxm = max(maxm, j - i);
        }
        ++j;
    }

    return maxm;
}

int main()
{

    return 0;
}