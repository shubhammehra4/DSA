#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    return 0;
}