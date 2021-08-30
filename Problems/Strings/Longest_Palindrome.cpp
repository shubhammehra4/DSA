#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s)
{
    unordered_map<char, int> m;

    for (auto i : s)
        m[i]++;

    int res = 0;
    bool flag = false;
    for (auto i : m)
    {
        if (i.second % 2 == 0)
            res += i.second;
        else
            res += i.second - 1, flag = true;
    }
    return flag ? res + 1 : res;
}

int main()
{
    return 0;
}