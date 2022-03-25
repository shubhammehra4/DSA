#include <bits/stdc++.h>
using namespace std;

string processString(string &s)
{
    string res;
    for (auto c : s)
    {
        if (c != '#')
            res.push_back(c);
        else if (!res.empty())
            res.pop_back();
    }

    return res;
}

bool backspaceCompare(string s, string t)
{
    return processString(s) == processString(t);
}