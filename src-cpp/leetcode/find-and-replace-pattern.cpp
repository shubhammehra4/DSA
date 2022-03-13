#include <bits/stdc++.h>
using namespace std;

string getPattern(string s)
{
    vector<int> mp(26, -1);
    string pattern = "";

    int cnt = 0;
    for (auto c : s)
    {
        if (mp[c - 'a'] == -1)
        {
            mp[c - 'a'] = '0' + cnt;
            cnt++;
        }

        pattern += mp[c - 'a'];
    }

    return pattern;
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    string modifiedPattern = getPattern(pattern);
    vector<string> res;

    for (auto word : words)
        if (modifiedPattern == getPattern(word))
            res.push_back(word);

    return res;
}