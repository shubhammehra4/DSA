#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &piles)
{
    sort(begin(piles), end(piles));

    int n = size(piles);
    int i = 0, j = n - 2;
    int res = 0;

    while (i < j)
    {
        res += piles[j];
        j -= 2;
        i += 1;
    }

    return res;
}

// Alter
int maxCoins(vector<int> &piles)
{
    sort(begin(piles), end(piles));
    int n = size(piles);
    int res = 0;

    for (int i = n / 3; i < n; i += 2)
        res += piles[i];

    return res;
}