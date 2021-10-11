#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

// SPF[] that store smallest prime factor of number
// [for Exp : smallest prime factor of '8' and '16'
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ]
void modifiedSieven(int n)
{
    vector<bool> isprime(n + 1, true);
    vector<int> prime;
    unordered_map<int, int> SPF;
    isprime[0] = isprime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }

        // Remove all multiples of  i*prime[j] which are not prime
        // and put smallest prime factor of i*Prime[j] as prime[j]
        for (int j = 0; j < prime.size() && i * prime[j] < n && prime[j] <= SPF[i]; j++)
        {
            isprime[i * prime[j]] = false;
            // put smallest prime factor of i*prime[j]
            SPF[i * prime[j]] = prime[j];
        }
    }

    for (int i = 0; i < prime.size() && prime[i] <= n; i++)
        cout << prime[i] << " ";
}

int main()
{
    int n = 30;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    sieveOfEratosthenes(n);
    return 0;
}
