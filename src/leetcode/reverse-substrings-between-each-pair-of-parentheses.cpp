#include <bits/stdc++.h>
using namespace std;

string reverseParenthesesBF(string s)
{
    stack<int> opened;
    string res;
    for (auto c : s)
    {
        if (c == '(')
            opened.push(res.size());
        else if (c == ')')
        {
            int j = opened.top();
            opened.pop();
            reverse(begin(res) + j, end(res));
        }
        else
            res += c;
    }

    return res;
}

string reverseParentheses(string s)
{
    int n = s.size();

    stack<int> opened;
    vector<int> jumpToPairs(n);
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
            opened.push(i);
        else if (s[i] == ')')
        {
            int j = opened.top();
            opened.pop();
            jumpToPairs[i] = j;
            jumpToPairs[j] = i;
        }
    }

    string res;
    for (int i = 0, direction = 1; i < n; i += direction)
    {
        if (s[i] == '(' || s[i] == ')')
            i = jumpToPairs[i], direction = -direction;
        else
            res += s[i];
    }
    return res;
}