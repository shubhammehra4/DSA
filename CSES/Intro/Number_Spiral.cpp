#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

bool isEven(int a)
{
    return a % 2 == 0;
}

li solve()
{
    li x, y;
    cin >> x >> y;

    if (x < y)
    {
        if (isEven(y))
        {
            li r = (y - 1) * (y - 1) + 1;
            return r + x - 1;
        }

        li r = y * y;
        return r - x + 1;
    }

    if (isEven(x))
    {
        li r = x * x;
        return r - y + 1;
    }

    li r = (x - 1) * (x - 1) + 1;
    return r + y - 1;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
        cout << solve() << endl;

    return 0;
}