#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (target == nums[mid])
            return mid;
        // there exists rotation; the middle element is in the left part of the array
        if (nums[mid] > nums[r])
        {
            if (target < nums[mid] && target >= nums[l])
                r = mid - 1;
            else
                l = mid + 1;
        }
        // there exists rotation; the middle element is in the right part of the array
        else if (nums[mid] < nums[l])
        {
            if (target > nums[mid] && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
        // there is no rotation; just like normal binary search
        else
        {
            if (target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    return -1;
}

// Alternative
int search(const vector<int> &A, int B)
{
    int n = A.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (A[mid] == B)
            return mid;
        else if (A[0] <= A[mid])
        {
            if (A[0] <= B && B < A[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (A[mid] < B && B <= A[n - 1])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> A = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    cout << search(A, 1);

    return 0;
}