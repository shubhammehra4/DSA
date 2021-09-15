#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    long long temp;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        sum -= temp;
    }
    cout << sum;
    return 0;
}