#include <bits/stdc++.h>
using namespace std;

// space optimised
int scoreOfParentheses(string s)
{
    int res = 0, layers = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            layers++;
        else
            layers--;

        if (s[i] == ')' && s[i - 1] == '(')
            res += 1 << layers;
    }

    return res;
}

// array with pointer
int scoreOfParentheses(string S)
{
    int res[30] = {0}, i = 0;

    for (char c : S)
    {
        if (c == '(')
            res[++i] = 0;
        else
            res[i - 1] += max(res[i] * 2, 1), i--;
    }

    return res[0];
}

// stack
int scoreOfParentheses(string s)
{
    stack<int> stack;
    int cur = 0;

    for (auto c : s)
    {
        if (c == '(')
        {
            stack.push(cur);
            cur = 0;
        }
        else
        {
            cur = stack.top() + max(2 * cur, 1);
            stack.pop();
        }
    }

    return cur;
}
