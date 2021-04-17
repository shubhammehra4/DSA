#include <bits/stdc++.h>
using namespace std;

int solve (int n, vector<int> &arr)
{
    long long sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 3 != 0)
        return 0;

    long long chk [n] = {0};
    long long sf = 0;
    sum = sum / 3;

    for (int i = n - 1; i >= 0; i--)
    {
        sf += arr[i];

        if (sf == sum  ) chk[i] = 1;
    }

    for (int i = 1; i < n; i++)
        chk[i] += chk[i - 1];

    long long cnt = 0, ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        cnt += arr[i];

        if (cnt == sum)
            ans += chk[n - 1] - chk[i + 1];
    }

    return ans;
}

int main()
{
    return 0;
}