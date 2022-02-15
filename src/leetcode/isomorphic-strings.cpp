#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    return normalize(s) == normalize(t);
}

string normalize(const string &s)
{
    char mapping[128] = {};
    string ans = "";
    char nextChr = 'a';
    for (char c : s)
    {
        if (mapping[c] == 0)
        {
            mapping[c] = nextChr;
            ++nextChr;
        }
        ans += mapping[c];
    }
    return ans;
}