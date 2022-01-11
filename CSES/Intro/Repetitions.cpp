#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long ans = 0, cnt = 0;
    for (long long i = 1; i < s.size(); i++)
    {
        cnt = s[i] == s[i - 1] ? cnt + 1 : 0;
        ans = max(ans, cnt);
    }

    cout << ans + 1;
    return 0;
}