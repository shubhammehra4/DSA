#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    string ans = ""; // we treat string as a stack
    for (char &c : num)
    {
        while (ans.size() != 0 && ans.back() > c && k != 0)
        {
            ans.pop_back();
            k--;
        }
        if (ans.size() != 0 || c != '0')
            ans.push_back(c);
    }
    while (ans.size() && k--)
        ans.pop_back();

    return (ans == "") ? "0" : ans;
}

string removeKdigits(string num, int k)
{
    stack<char> st;
    string ans = "";
    for (char &c : num)
    {
        while (!st.empty() && st.top() > c && k != 0)
        {
            st.pop();
            k--;
        }

        if (st.size() != 0 || c != '0')
            st.push(c);
    }

    while (!st.empty() && k--)
        st.pop();

    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }

    return (ans == "") ? "0" : ans;
}
