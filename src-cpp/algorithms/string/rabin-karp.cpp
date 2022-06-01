#include <bits/stdc++.h>
using namespace std;

bool areEqual(string &pattern, string &text, int startIdx)
{
    for (int i = 0; i < size(pattern); i++)
        if (pattern[i] != text[i + startIdx])
            return false;

    return true;
}

vector<int> rabinKarp(string &pattern, string &text)
{
    const int d = 256; // no. of characters in the input array
    const int prime = 257;
    int m = size(pattern), n = size(text);

    // h = "pow(d, m-1)%q"
    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % prime;

    int patternHash = 0;
    int textWindowHash = 0;
    for (int i = 0; i < m; i++)
    {
        patternHash = (d * patternHash + (int)pattern[i]) % prime;
        textWindowHash = (d * textWindowHash + (int)text[i]) % prime;
    }

    vector<int> occurences;
    for (int i = 0; i <= n - m; i++)
    {
        if (patternHash == textWindowHash && areEqual(pattern, text, i))
            occurences.push_back(i);

        if (i < n - m)
        {
            textWindowHash = (d * (textWindowHash - text[i] * h) + text[i + m]) % prime;

            if (textWindowHash < 0)
                textWindowHash = textWindowHash + prime;
        }
    }

    return occurences;
}

// alter
// vector<int> rabin_karp(string const &pattern, string const &text)
// {
//     const int prime = 31;
//     const int M = 1e9 + 9;
//     int m = size(pattern), n = size(text);

//     vector<long long> p_pow(max(m, n)); // pre compute
//     p_pow[0] = 1;
//     for (int i = 1; i < (int)p_pow.size(); i++)
//         p_pow[i] = (p_pow[i - 1] * prime) % M;

//     vector<long long> hashes(n + 1, 0);
//     for (int i = 0; i < n; i++)
//         hashes[i + 1] = (hashes[i] + (text[i] - 'a' + 1) * p_pow[i]) % M;

//     long long patternHash = 0;
//     for (int i = 0; i < m; i++)
//         patternHash = (patternHash + (pattern[i] - 'a' + 1) * p_pow[i]) % M;

//     vector<int> occurences;

//     for (int i = 0; i + m - 1 < n; i++)
//     {
//         long long cur_h = (hashes[i + m] + M - hashes[i]) % M;
//         if (cur_h == patternHash * p_pow[i] % M)
//             occurences.push_back(i);
//     }

//     return occurences;
// }