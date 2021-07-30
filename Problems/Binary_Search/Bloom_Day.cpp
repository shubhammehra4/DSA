/*
Given an integer array bloomDay, an integer m and an integer k.

We need to make m bouquets. To make a bouquet, you need to use k adjacent 
flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and 
then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets 
from the garden. If it is impossible to make m bouquets return -1.
*/

#include <bits/stdc++.h>
using namespace std;

//Get the number of bouquets of size k at a certain day.
int getBouq(vector<int> &bloomDay, int day, int k)
{
    int res = 0, cnt = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= day)
            cnt++;
        else
            cnt = 0;
        //Reset the window size to 0 to consider the case with 2*k or more continous bloomed flowers.
        if (cnt == k)
            res++, cnt = 0;
    }
    return res;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    if (bloomDay.size() < m * k)
        return -1;

    auto p = minmax_element(bloomDay.begin(), bloomDay.end());
    int r = *p.second, l = *p.first;
    int mid;
    while (l < r)
    {
        mid = (l + r) >> 1;

        if (getBouq(bloomDay, mid, k) < m)
            l = mid + 1;
        else
            r = mid;
    }

    return getBouq(bloomDay, l, k) >= m ? l : -1;
}

int main()
{

    return 0;
}