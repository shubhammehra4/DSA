#include <bits/stdc++.h>
using namespace std;

int minFlipsMonoIncr(string s)
{
    int idx = 0;
    int n = s.size();

    while (idx < n && s[idx] == '0')
        idx++;

    int one = 0;
    int flip = 0;

    for (; idx < n; idx++)
    {
        if (s[idx] == '1')
            one++; // num of 1's encountered till now
        else
            flip++; // nums to flip till now

        flip = min(flip, one);
    }

    return flip;
}

// Alter
int minFlipsMonoIncr(string s)
{
    int flips = 0, counter = 0;
    for (auto c : s)
    {
        if (c == '1')
            counter++;
        else
            flips++;

        flips = min(flips, counter);
    }

    return flips;
}