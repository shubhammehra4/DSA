#include <bits/stdc++.h>
using namespace std;

// sum of n natutral number - sum of array can also be used
int main()
{
    long long n;
    cin >> n;

    int XOR = 1;
    for (int i = 2; i <= n; i++)
        XOR ^= i;

    long long temp;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        XOR ^= temp;
    }

    cout << XOR;
    return 0;
}