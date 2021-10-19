#include <bits/stdc++.h>
using namespace std;

// Condition nums[-1] = nums[n] = -∞.
/*
 What we are essentially doing is going in the direction of the rising slope(by choosing the 
 element which is greater than current). How does that guarantee the result? => 
 
 a) rising slope has to keep rising till end of the array 
 b) rising slope will encounter a lesser element and go down.
 In a) the answer is the end element because we take the boundary as -INFINITY 
 b) the answer is the largest element before the slope falls. Hope this makes things clearer.

*/

int findPeakElement(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;

    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] < nums[m + 1])
            l = m + 1;
        else
            r = m;
    }

    return l;
}