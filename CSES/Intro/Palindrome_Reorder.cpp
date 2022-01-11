#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isOdd(ll n)
{
    return n % 2 != 0;
}

int main()
{
    vector<ll> cnt(26, 0);
    string s;
    cin >> s;

    for (char c : s)
        cnt[c - 'A']++;

    int oddCnt = 0;
    for (auto i : cnt)
        oddCnt += isOdd(i) ? 1 : 0;

    if (oddCnt > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    string result;
    for (int i = 0; i < 26; i++)
    {
        if (!isOdd(cnt[i]))
        {
            for (ll j = 0; j < cnt[i] / 2; j++)
                result.push_back(i + 'A');
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (isOdd(cnt[i]))
        {
            for (ll j = 0; j < cnt[i]; j++)
                result.push_back(i + 'A');
        }
    }

    for (int i = 25; i >= 0; i--)
    {
        if (!isOdd(cnt[i]))
        {
            for (ll j = 0; j < cnt[i] / 2; j++)
                result.push_back(i + 'A');
        }
    }

    cout << result << endl;

    return 0;
}