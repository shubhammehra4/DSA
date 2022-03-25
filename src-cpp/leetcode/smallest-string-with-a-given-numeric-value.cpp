#include <bits/stdc++.h>
using namespace std;

string getSmallestString(int n, int k)
{
    string res(n, 'a');

    k -= n;
    int i = n - 1;
    while (k > 0 && i >= 0)
    {
        res[i--] += min(25, k);
        k -= min(25, k);
    }

    return res;
}