#include <bits/stdc++.h>
using namespace std;

bool isEven(long long int a)
{
    return a % 2 == 0;
}

int main()
{
    long long int n;
    cin >> n;

    while (n != 1)
    {
        cout << n << " ";
        if (isEven(n))
            n /= 2;
        else
            n = (n * 3) + 1;
    }
    cout << n;

    return 0;
}