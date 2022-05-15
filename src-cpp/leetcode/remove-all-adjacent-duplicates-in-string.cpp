#include <bits/stdc++.h>
using namespace std;

// optimised - string as stack
string removeDuplicates(string s)
{
    string res = "";

    for (auto c : s)
    {
        if (c == res.back())
            res.pop_back();
        else
            res.push_back(c);
    }

    return res;
}

// stack
string removeDuplicates(string s)
{
    stack<char> st;
    for (auto c : s)
    {
        if (!st.empty() && c == st.top())
            st.pop();
        else
            st.push(c);
    }

    string res = "";
    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }

    return res;
}