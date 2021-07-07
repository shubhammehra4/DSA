#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string A)
{
    stack<string> st;
    string dir;
    string res;
    res.append("/");
    int n = A.length();

    for (int i = 0; i < n; i++)
    {
        dir.clear();
        while (A[i] == '/')
            i++;
        while (i < n && A[i] != '/')
        {
            dir.push_back(A[i]);
            i++;
        }

        if (dir.compare("..") == 0)
        {
            if (!st.empty())
                st.pop();
        }
        else if (dir.compare(".") == 0)
            continue;
        else if (dir.length() != 0)
            st.push(dir);
    }

    stack<string> st1;
    while (!st.empty())
    {
        st1.push(st.top());
        st.pop();
    }

    while (!st1.empty())
    {
        string temp = st1.top();

        if (st1.size() != 1)
            res.append(temp + "/");
        else
            res.append(temp);

        st1.pop();
    }

    return res;
}

int main()
{
    cout << simplifyPath("/home/a/b///./c/f/../e");

    return 0;
}