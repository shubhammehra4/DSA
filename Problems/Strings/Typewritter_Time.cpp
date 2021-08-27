#include <bits/stdc++.h>
using namespace std;

int minTimeToType(string word)
{
    int res = word.size(), pos = 'a';
    for (auto ch : word)
    {
        res += min(abs(ch - pos), 26 - abs(pos - ch));
        pos = ch;
    }
    return res;
}

int main()
{

    return 0;
}