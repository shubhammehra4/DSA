#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll powmod(ll base, ll exponent)
{
    if (exponent < 0)
        exponent += MOD - 1;

    ll ans = 1;

    while (exponent)
    {
        if (exponent & 1)
            ans = (ans * base) % MOD;

        base = (base * base) % MOD;
        exponent /= 2;
    }

    return ans;
}

int cityTour(int A, vector<int> &B)
{
    sort(B.begin(), B.end());
    long long fact[10000];
    fact[0] = 1;

    for (int i = 1; i < 10000; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    vector<long long> gaps;
    long long n = B.size();
    gaps.push_back(B[0] - 1);

    for (int i = 1; i < n; i++)
        gaps.push_back(B[i] - B[i - 1] - 1);

    gaps.push_back(A - B[n - 1]);
    long long ans = 1;
    long long sum = 0, pro = 1;

    for (int i = 0; i < gaps.size(); i++)
    {
        if (gaps[i] == 0)
            continue;

        if (i != 0 && i != gaps.size() - 1)
            ans = (ans * powmod(2, gaps[i] - 1)) % MOD;

        sum = (sum + gaps[i]) % MOD;
        pro = (pro * fact[gaps[i]]) % MOD;
    }

    ans = (ans * fact[sum]) % MOD;
    ans = (ans * powmod(pro, MOD - 2)) % MOD;
    return ans;
}

int main()
{
    return 0;
}