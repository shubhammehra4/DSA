#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (auto &i : arr)
        cin >> i;

    long long ans = 0;

    for (long long i = 1; i < n; i++)
    {
        long long diff = arr[i - 1] - arr[i];
        if (diff > 0)
        {
            ans += diff;
            arr[i] += diff;
        }
    }

    cout << ans;

    return 0;
}