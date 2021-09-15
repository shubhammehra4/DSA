#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long ans = 0, cnt = 0;
    for (long long i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            cnt++;
        else
            cnt = 0;
        if (cnt > ans)
            ans = cnt;
    }

    cout << ans + 1;
    return 0;
}