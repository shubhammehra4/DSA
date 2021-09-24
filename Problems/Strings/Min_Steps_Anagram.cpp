#include <bits/stdc++.h>
using namespace std;

int minSteps(string s, string t)
{
    vector<int> m(26, 0);

    for (auto c : s)
        m[c - 'a']++;

    for (auto c : t)
        m[c - 'a']--;

    int ans = 0;
    for (auto i : m)
        ans += abs(i);

    return ans / 2;

    // alternative
    // for (auto i : m)
    //     ans += i > 0 ? i : 0;

    // return ans;
}

int main()
{
    return 0;
}