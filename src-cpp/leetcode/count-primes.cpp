#include <bits/stdc++.h>
using namespace std;

vector<bool> sieveOfEratosthenes(int num)
{
    vector<bool> prime(num + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= num; p++)
    {
        if (prime[p] == true)
            for (int i = p * p; i <= num; i += p)
                prime[i] = false;
    }

    return prime;
}

int countPrimes(int n)
{
    int count = 0;
    vector<bool> prime = sieveOfEratosthenes(n);

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
            count++;
    }

    return count;
}