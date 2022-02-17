#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1;
    int right = *max_element(begin(piles), end(piles));

    while (left < right)
    {
        int rate = (left + right) / 2;
        int hourSpent = 0;

        for (int pile : piles)
            hourSpent += pile / rate + (pile % rate != 0);

        if (hourSpent <= h)
            right = rate;
        else
            left = rate + 1;
    }

    return right;
}

// Brute Force TLE
int minEatingSpeedBF(vector<int> &piles, int h)
{
    int rate = 1;

    while (true)
    {
        int hourSpent = 0;

        for (int pile : piles)
        {
            hourSpent += pile / rate + (pile % rate != 0);

            if (hourSpent > h)
                break;
        }

        if (hourSpent <= h)
            return rate;
        rate += 1;
    }

    return rate;
}