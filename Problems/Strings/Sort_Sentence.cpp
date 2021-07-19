#include <bits/stdc++.h>
using namespace std;

string sortSentence(string s)
{
    string res = "";
    map<int, string> m;
    string temp = "";

    for (auto i : s)
    {
        if (i >= 48 && i <= 57)
        {
            m[(int)i] = temp;
            temp = "";
        }
        else if (i != 32)
            temp += i;
    }

    for (auto i : m)
        res += i.second + " ";
    res.pop_back();

    return res;
}

int main()
{
    return 0;
}