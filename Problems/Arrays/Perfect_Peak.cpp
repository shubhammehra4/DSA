#include <bits/stdc++.h>
using namespace std;

int perfectPeak(vector<int> &A)
{
    int n = A.size();
    vector<int> max_l(n);
    vector<int> min_r(n);

    max_l[0] = A[0];
    for (int i = 1; i < n; i++)
        max_l[i] = max(max_l[i - 1], A[i]);

    min_r[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
        min_r[i] = min(min_r[i + 1], A[i]);

    for (int i = 1; i < n - 1; i++)
    {
        if (max_l[i] != max_l[i - 1] && min_r[i + 1] != min_r[i])
            return 1;
    }

    return 0;
}

int main()
{

    return 0;
}