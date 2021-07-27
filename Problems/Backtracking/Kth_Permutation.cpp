#include <bits/stdc++.h>
using namespace std;

int fact(int n, int B)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
        if (res > B)
            return B + 1;
    }
    return res;
}

string getPermutation(int A, int B)
{
    set<int> hash;
    string res = "";
    int t, c, f;
    B--;
    for (int i = 1; i <= A; i++)
        hash.insert(i);

    while (B > 0)
    {
        f = fact(--A, B);
        t = B / f;
        auto it = hash.begin();
        advance(it, t);
        c = *(it);
        res += to_string(c);
        hash.erase(c);
        B = B % f;
    }

    for (auto it = hash.begin(); it != hash.end(); it++)
        res += to_string(*it);

    return res;
}

int main()
{

    return 0;
}