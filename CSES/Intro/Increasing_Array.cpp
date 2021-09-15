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
        if (arr[i] < arr[i - 1])
        {
            ans += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    cout << ans;

    return 0;
}