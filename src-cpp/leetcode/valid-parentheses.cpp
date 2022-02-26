#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (auto &c : s)
    {
        if (c == '[' || c == '{' || c == '(')
            st.push(c);
        else if (st.empty())
            return false;
        else
        {
            if (c == ']' && st.top() == '[')
                st.pop();
            else if (c == '}' && st.top() == '{')
                st.pop();
            else if (c == ')' && st.top() == '(')
                st.pop();
            else
                return false;
        }
    }

    return st.empty();
}

bool isValid(string s)
{
    stack<char> st;

    for (auto &c : s)
    {
        switch (c)
        {
        case '(':
        case '[':
        case '{':
            st.push(c);
            break;

        case ')':
            if (st.empty() || st.top() != '(')
                return false;
            st.pop();
            break;
        case ']':
            if (st.empty() || st.top() != '[')
                return false;
            st.pop();
            break;
        case '}':
            if (st.empty() || st.top() != '{')
                return false;
            st.pop();
            break;
        }
    }

    return st.empty();
}