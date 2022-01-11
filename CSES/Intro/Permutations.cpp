#include <bits/stdc++.h>
using namespace std;

void printOdds(long long n)
{
    for (long long i = 1; i <= n; i += 2)
        cout << i << " ";
}

void printEvens(long long n)
{
    for (long long i = 2; i <= n; i += 2)
        cout << i << " ";
}

int main()
{
    long long n;
    cin >> n;

    if (n == 1)
        cout << 1 << endl;
    else if (n < 4)
        cout << "NO SOLUTION" << endl;
    else
    {
        printEvens(n);
        printOdds(n);
    }

    return 0;
}