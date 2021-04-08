#include <bits/stdc++.h>
using namespace std;

vector<int> primesum (int n)
{
    int a = 0, b = 0;
    vector<bool>isPrime (n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++)
    {
        if (isPrime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (isPrime[i] && isPrime[n - i])
        {
            if (a <= i && b < (n - 1) )
            {
                a = i;
                b = n - i;
            }
        }
    }

    vector<int> res{b, a};
    return res;
}

int main()
{
    int a = 1290;
    vector<int> result = primesum (a);

    for (auto &i : result)
    {
        cout << i << ' ';
    }

    return 0;
}