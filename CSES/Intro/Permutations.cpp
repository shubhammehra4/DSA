#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n == 1)
        cout << 1 << endl;
    else if (n < 4)
        cout << "NO SOLUTION" << endl;
    else if (n == 4)
        cout << "2 4 1 3";
    else
    {
        for (long long i = 1; i <= n; i += 2)
            cout << i << " ";
        for (long long i = 2; i <= n; i += 2)
            cout << i << " ";
    }
    return 0;
}