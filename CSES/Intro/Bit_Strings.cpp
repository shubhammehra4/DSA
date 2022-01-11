#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const long long int MOD = 1000000007;

int main()
{
    lli n;
    cin >> n;

    lli res = 1;
    while (n)
    {
        res = (res << 1) % MOD;
        n--;
    }

    cout << res;
    return 0;
}