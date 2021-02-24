#include <bits/stdc++.h>
using namespace std;

//Iterative
int ifib (int n)
{
    if (n <= 1)
        return n;
    else
    {
        int a = 0, b = 1, temp;

        for (int i = 2; i <= n; i++)
        {
            temp = b;
            b = a + b;
            a = temp;
        }

        return b;
    }
}
//Dynamic  Iteration
class dpfib {
    public:
        int fib (n) {
            int f[n + 2];
            int f[0] = 0;
            int f[1] = 1;

            for (int i = 2; i <= n; i++) {
                f[i] = f[i - 1] + f[i - 2];
            }

            return f[n];
        }
};

//Recursive
int recfib (int n)
{
    if (n <= 1)
        return n;
    else
        return (recfib (n - 1) + recfib (n - 2) );
}

// O(log n)
void multiply (int F[2][2], int M[2][2])
{
    int x =  F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y =  F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z =  F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w =  F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power (int F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;

    int M[2][2] = {{1, 1}, {1, 0}};
    power (F, n / 2);
    multiply (F, F);

    if (n % 2 != 0)
        multiply (F, M);
}

int lognfib (int n)
{
    int F[2][2] = {{1, 1}, {1, 0}};

    if (n == 0)
        return 0;

    power (F, n - 1);
    return F[0][0];
}

//DP
int term[10000] = {0;
int memoizedfib(int n)
{
    if(n<=1)
        return n;
    if(term[n]!=0)
        return term[n];
    else
    {
        term[n] = fib(n - 1) + fib(n - 2); 
        return term[n];
    }

}
//Formula O(1)
int bestfib (int n)
{
    double phi = (1 + sqrt (5) ) / 2;
    return round (pow (phi, n) / sqrt (5) );
}

int main()
{
    int n;
    cin >> n;
    dpfib obj;
    cout << ifib (n); //O(n)
    cout << recfib (n); //O(n)
    int x = obj.fib (n); //O(n)
    cout << x;
    cout << lognfib (n); //O(log n)
    cout << bestfib (n); //O(1)
    return 0;
}