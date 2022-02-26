#include <bits/stdc++.h>
using namespace std;

void backtrack(string &s, int i, vector<string> &res)
{
    if (i == s.size())
    {
        res.push_back(s);
        return;
    }

    backtrack(s, i + 1, res);

    if (isalpha(s[i]))
    {
        s[i] = islower(s[i]) ? toupper(s[i]) : tolower(s[i]);
        backtrack(s, i + 1, res);
    }
}
vector<string> letterCasePermutation(string S)
{
    vector<string> res;
    backtrack(S, 0, res);
    return res;
}