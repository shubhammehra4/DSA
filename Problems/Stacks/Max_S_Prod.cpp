/*
You are given an array A containing N integers. 
The special product of each ith integer in this array is defined 
as the product of the following:

    LeftSpecialValue: For an index i, it is defined as the index j such that 
        A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, 
        the LeftSpecialValue is the maximum value of j.
    RightSpecialValue: For an index i, it is defined as the index j such that 
        A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, 
        the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.
*/
#include <bits/stdc++.h>
using namespace std;

int maxSpecialProduct(vector<int> &A)
{
    int n = A.size();
    vector<int> LSValue(n, 0), RSValue(n, 0);

    stack<int> leftMax;
    leftMax.push(0);
    LSValue[0] = 0;
    for (int i = 1; i < n; i++)
    {
        while (!leftMax.empty())
        {
            if (A[leftMax.top()] > A[i])
                break;
            leftMax.pop();
        }
        LSValue[i] = (leftMax.empty()) ? 0 : leftMax.top();
        leftMax.push(i);
    }

    stack<int> rightMax;
    rightMax.push(n - 1);
    RSValue[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        while (!rightMax.empty())
        {
            if (A[rightMax.top()] > A[i])
                break;
            rightMax.pop();
        }
        RSValue[i] = (rightMax.empty()) ? 0 : rightMax.top();
        rightMax.push(i);
    }

    long long mx = -1;
    for (int i = 0; i < n; i++)
        mx = max(mx, LSValue[i] * 1LL * RSValue[i]);

    return mx % 1000000007;
}

int main()
{

    return 0;
}