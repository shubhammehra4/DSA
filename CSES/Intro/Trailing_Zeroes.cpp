#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;

    int cntOfFive = 0; // no. of 2's in prime factors is always greater than or equal

    for (int i = 5; n / i >= 1; i *= 5)
        cntOfFive += n / i;

    cout << cntOfFive;

    return 0;
}