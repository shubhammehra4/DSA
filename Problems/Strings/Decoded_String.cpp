#include <bits/stdc++.h>
using namespace std;

string decodeAtIndex(string S, int k)
{
    long size = 0;
    int N = S.size();

    for (auto c : S)
    {
        if (isdigit(c))
            size *= c - '0';
        else
            size++;
    }

    for (int i = N - 1; i >= 0; --i)
    {
        k %= size;
        if (k == 0 && isalpha(S[i]))
            return (string) "" + S[i];

        if (isdigit(S[i]))
            size /= S[i] - '0';
        else
            size--;
    }

    return S.substr(k, 1);
}

int main()
{

    return 0;
}