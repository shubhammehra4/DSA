/*
Given an array nums with n integers, your task is to check if it could become non-decreasing 
by modifying at most one element.
*/
#include <bits/stdc++.h>
using namespace std;

bool checkPossibility(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 1; i < nums.size() && cnt <= 1; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            cnt++;
            if (i - 2 < 0 || nums[i - 2] <= nums[i])
                nums[i - 1] = nums[i];
            else
                nums[i] = nums[i - 1];
        }
    }
    return cnt <= 1;
}