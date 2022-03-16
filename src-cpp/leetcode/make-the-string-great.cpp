#include <bits/stdc++.h>
using namespace std;

string makeGood(string s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
        while (!st.empty() && abs(s[i + 1] - st.top()) == 32)
            st.pop(), i++;
    }

    string res = "";
    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }

    return res;
}

string makeGood(string s)
{
    int p = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (p > 0 && abs(s[i] - s[p - 1]) == 32)
            --p;
        else
            s[p++] = s[i];
    }

    return s.substr(0, p);
}

// brute force
string makeGood(string s)
{
    int n = 0;

    while (n != s.size())
    {
        n = s.size();
        for (int i = 0; i + 1 < s.size(); ++i)
            if (abs(s[i] - s[i + 1]) == 32)
                s = s.substr(0, i) + s.substr(i + 2);
    }

    return s;
}