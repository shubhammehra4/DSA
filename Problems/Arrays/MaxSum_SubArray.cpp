// Find the contiguous subarray within an array, A of length N which has the largest sum.
#include <bits/stdc++.h>
using namespace std;

int TrivialAlgo(int a[], int n)
{
    int max = a[0], sum;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
                sum += a[k];
            if (max < sum)
                max = sum;
        }
    }
    return max;
}

int AlternateAlgo(int a[], int n)
{
    int s[n];
    s[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] > 0)
            s[i] = s[i - 1] + a[i];
        else
            s[i] = a[i];
    }
    sort(s, s + n);
    return s[n - 1];
}

int maxSubArray(const vector<int> &A)
{
    int n = A.size();
    int curSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curSum += A[i];
        maxSum = max(maxSum, curSum);
        if (curSum < 0)
            curSum = 0;
    }
    return maxSum;
}

int main()
{
    int a[] = {1, 5, 6, 8, -4, 3, 5, 12, 13, 0, -1, 19, -9, -5, 15, 10, 5, 4, 1, 7, 3, 8, -3, 5, 18, -9, 1, 3};

    cout << "Max Sum is: " << TrivialAlgo(a, 28) << endl;
    cout << "Max Sum(Method-2) is: " << AlternateAlgo(a, 28) << endl;
}