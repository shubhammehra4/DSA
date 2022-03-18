#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s)
{
    int res = 0, right = 0;

    for (char &c : s)
    {
        if (c == '(')
        {
            if (right % 2 > 0)
            {
                right--;
                res++;
            }
            right += 2;
        }
        else
        {
            right--;
            if (right < 0)
            {
                right += 2;
                res++;
            }
        }
    }

    return right + res;
}

// stack
int minInsertions(string s)
{
    int n = s.size();
    int res = 0;
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else
        {
            if (st.empty())
            {
                if (i < n - 1 && s[i + 1] == ')')
                    res++, i++;
                else
                    res += 2;
            }
            else
            {
                st.pop();
                if (i < n - 1 && s[i + 1] == ')')
                    i++;
                else
                    res++;
            }
        }
    }

    while (!st.empty())
    {
        st.pop();
        res += 2;
    }

    return res;
}
