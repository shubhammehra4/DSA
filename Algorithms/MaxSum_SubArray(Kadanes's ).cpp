#include <bits/stdc++.h>
using namespace std;

void maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
        start = 0, end = 0, s = 0;
    for (int i = 0; i < size; i++)
    {
        max_ending_here += a[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is " << max_so_far << endl;
    cout << "Starting index " << start << endl
         << "Ending index " << end;
}

int maxAbsoluteSumSubArray(vector<int> &a)
{
    int maxm_sum = INT_MIN, max_ending_here = 0;
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        max_ending_here += a[i];
        maxm_sum = max(maxm_sum, max_ending_here);
        if (max_ending_here < 0)
            max_ending_here = 0;
    }

    int min_ending_here = 0, minm_sum = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        min_ending_here += a[i];
        minm_sum = min(minm_sum, min_ending_here);
        if (min_ending_here > 0)
            min_ending_here = 0;
    }

    return max(abs(maxm_sum), abs(minm_sum));
}

int main()
{
    int a[] = {1, 5, 6, 8, -4, 3, 5, 12, 13, 0,
               -1, 19, -9, -5, 15, 10, 5, 4, 1,
               7, 3, 8, -3, 5, 18, -9, 1, 3};
    maxSubArraySum(a, 12);
}