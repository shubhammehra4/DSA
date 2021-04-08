#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int fib (int n)
{
    if (n <= 1)
        return n;

    return fib (n - 1) + fib (n - 2);
}

//Iterative
ll ifib (ll n)
{
    if (n <= 1)
        return n;
    else
    {
        ll a = 0, b = 1, temp;

        for (ll i = 2; i <= n; i++)
        {
            temp = b;
            b = a + b;
            a = temp;
        }

        return b;
    }
}

// Matrix Multiplication
void multiply (ll F[2][2], ll M[2][2])
{
    ll x =  F[0][0] * M[0][0] + F[0][1] * M[1][0];
    ll y =  F[0][0] * M[0][1] + F[0][1] * M[1][1];
    ll z =  F[1][0] * M[0][0] + F[1][1] * M[1][0];
    ll w =  F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power (ll F[2][2], ll n)
{
    if (n == 0 || n == 1)
        return;

    ll M[2][2] = {{1, 1}, {1, 0}};
    power (F, n / 2);
    multiply (F, F);

    if (n % 2 != 0)
        multiply (F, M);
}

ll lognfib (ll n)
{
    ll F[2][2] = {{1, 1}, {1, 0}};

    if (n == 0)
        return 0;

    power (F, n - 1);
    return F[0][0];
}

//DP
ll term[10000] = {0};
ll memoizedfib (ll n)
{
    if (n <= 1)
        return n;

    if (term[n] != 0)
        return term[n];
    else
    {
        term[n] = memoizedfib (n - 1) + memoizedfib (n - 2);
        return term[n];
    }
}

//Formula O(1)
ll bestfib (ll n)
{
    double phi = (1 + sqrt (5) ) / 2;
    return round (pow (phi, n) / sqrt (5) );
}

int main()
{
    ll n;
    cin >> n;
    cout << "Recursive: " << fib (n) << endl; //Exponential
    cout << "Space Optimised Iteration: " << ifib (n) << endl; //Exponential
    cout << "Matrix Multiplication: " << lognfib (n) << endl; //O(lon n)
    cout << "Memoized: " << memoizedfib (n) << endl; //O(n) || O(1)
    cout << "Formula: " << bestfib (n); //O(1)
    return 0;
}