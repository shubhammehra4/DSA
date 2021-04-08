#include <bits/stdc++.h>
using namespace std;

bool isPower (int n)
{
    if (n == 1) return true;

    for (int x = 2; x <= sqrt (n); x++)
    {
        unsigned y = 2;
        unsigned p = pow (x, y);

        while (p <= n && p > 0)
        {
            if (p == n)
                return true;

            y++;
            p = pow (x, y);
        }
    }

    return false;
}

int main()
{
    int a =  536870912;
    cout << isPower (a);
    return 0;
}