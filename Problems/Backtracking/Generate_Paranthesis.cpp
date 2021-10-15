#include <bits/stdc++.h>
using namespace std;

// Recursive
vector<string> generateParenthesis(int n)
{
    vector<string> res;

    backTrackingFun(n, n, "", res);
    return res;
}
/**
 * lb - no. of '(' in the string
 * rb - no. of ')' in the string
*/

void backTrackingFun(int lb, int rb, string curr, vector<string> &res)
{
    if (lb == 0 && rb == 0)
    {
        res.push_back(curr);
        return;
    }

    if (lb > 0)
    {
        backTrackingFun(lb - 1, rb, curr + '(', res);
    }

    if (rb > lb)
    {
        backTrackingFun(lb, rb - 1, curr + ')', res);
    }
}

// Iterative

/**
 * remainingLBr - No. of '(' not inserted into the string => can append '('
 * diff - differrence between '(' and ')' => can append ')'
*/
struct helper
{
    string s;
    int remainingLBr;
    int diff;
};
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    stack<helper> s;

    s.push({"", n, 0});
    while (!s.empty())
    {
        helper h = s.top();
        s.pop();
        if (h.remainingLBr == 0 && h.diff == 0)
        {
            result.push_back(h.s);
            continue;
        }

        if (h.remainingLBr > 0)
            s.push({h.s + "(", h.remainingLBr - 1, h.diff + 1});

        if (h.diff > 0)
            s.push({h.s + ")", h.remainingLBr, h.diff - 1});
    }

    return result;
}