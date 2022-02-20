#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> set;
    int n = s.size(), ans = 0;
    int start = 0, end = 0;

    while (start < n && end < n)
    {
        if (set.find(s[end]) == set.end())
        {
            set.insert(s[end++]);
            ans = max(ans, end - start);
        }
        else
            set.erase(s[start++]);
    }

    return ans;
}