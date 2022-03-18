#include <bits/stdc++.h>
using namespace std;

// space optimized
string minRemoveToMakeValid(string s)
{
    int count = 0;

    for (auto i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            count++;
        else if (s[i] == ')')
        {
            if (count != 0)
                count--;
            else
                s[i] = '*';
        }
    }

    count = 0;
    for (auto i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ')')
            count++;
        else if (s[i] == '(')
        {
            if (count != 0)
                count--;
            else
                s[i] = '*';
        }
    }

    string res = "";

    for (auto c : s)
        if (c != '*')
            res += c;

    return res;
}

// stack
string minRemoveToMakeValid(string s)
{
    stack<int> st;

    for (auto i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')')
        {
            if (!st.empty())
                st.pop();
            else
                s[i] = '*';
        }
    }

    while (!st.empty())
    {
        s[st.top()] = '*';
        st.pop();
    }

    s.erase(remove(begin(s), end(s), '*'), end(s));

    return s;
}
