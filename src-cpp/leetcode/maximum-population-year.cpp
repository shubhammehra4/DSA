#include <bits/stdc++.h>
using namespace std;

// counting
int maximumPopulation(vector<vector<int>> &logs)
{
    vector<int> population(101, 0);
    int res = 0;

    for (auto &l : logs)
    {
        ++population[l[0] - 1950];
        --population[l[1] - 1950];
    }

    for (auto i = 1; i < 100; ++i)
    {
        population[i] += population[i - 1];

        res = population[i] > population[res] ? i : res;
    }

    return res + 1950;
}