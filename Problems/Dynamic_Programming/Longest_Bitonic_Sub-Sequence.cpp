#include <bits/stdc++.h>
using namespace std;

int lbs(vector<int> arr)
{
    int i, j;
    int n = arr.size();

    vector<int> lis(n);
    for (i = 0; i < n; i++)
        lis[i] = 1;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    vector<int> lds(n);
    for (i = 0; i < n; i++)
        lds[i] = 1;

    for (i = n - 2; i >= 0; i--)
        for (j = n - 1; j > i; j--)
            if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;

    /* Return the maximum value of lis[i] + lds[i] - 1*/
    int max = lis[0] + lds[0] - 1;
    for (i = 1; i < n; i++)
        if (lis[i] + lds[i] - 1 > max)
            max = lis[i] + lds[i] - 1;

    return max;
}

int main()
{
    return 0;
}