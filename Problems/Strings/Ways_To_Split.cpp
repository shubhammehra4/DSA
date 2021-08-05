/*
Given a binary string s (a string consisting only of '0's and '1's), 
we can split s into 3 non-empty strings s1, s2, s3 (s1+ s2+ s3 = s).

Return the number of ways s can be split such that the number of 
characters '1' is the same in s1, s2, and s3.
*/
#include <bits/stdc++.h>
using namespace std;

int numWays(string s)
{
    long long int MOD = 1000000007, cnt = 0;
    for (auto i : s)
        sum += (i - '0');

    if (sum % 3 != 0)
        return 0;

    if (sum == 0)
        return (((s.length() - 2) * (s.length() - 1)) / 2) % MOD;

    long long int first_cut = 0, second_cut = 0, k = (sum / 3), c = 0;
    for (auto i : s)
    {
        if (i == '1')
            c++;

        if (c == k)
            first_cut++;
        else if (c == 2 * k)
            second_cut++;
    }

    first_cut = ((first_cut)*second_cut) % MOD;
    return first_cut;
}

int main()
{

    return 0;
}