#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int gasTank = 0, total = 0, start = 0;

    for (int stationIdx = 0; stationIdx < gas.size(); stationIdx++)
    {
        int consume = gas[stationIdx] - cost[stationIdx];
        gasTank += consume;
        total += consume;
        if (gasTank < 0)
        {
            start = stationIdx + 1;
            gasTank = 0;
        }
    }

    return total < 0 ? -1 : start;
}

int canCompleteCircuitAlter(vector<int> &gas, vector<int> &cost)
{
    auto gasSum = accumulate(begin(gas), end(gas), 0);
    auto costSum = accumulate(begin(cost), end(cost), 0);

    if (gasSum < costSum)
        return -1;

    int gasTank = 0, start = 0;

    for (int stationIdx = 0; stationIdx < gas.size(); stationIdx++)
    {
        gasTank += gas[stationIdx] - cost[stationIdx];

        if (gasTank < 0)
        {
            start = stationIdx + 1;
            gasTank = 0;
        }
    }

    return start;
}

int canCompleteCircuitAlter2(vector<int> &gas, vector<int> &cost)
{
    int gasTank = 0, start = 0;

    vector<int> diff(gas.size());
    std::transform(begin(gas), end(gas), begin(cost), begin(diff), std::minus<int>());
    auto total = accumulate(begin(diff), end(diff), 0);
    if (total < 0)
        return -1;

    for (int stationIdx = 0; stationIdx < gas.size(); stationIdx++)
    {
        int consume = gas[stationIdx] - cost[stationIdx];
        gasTank += consume;

        if (gasTank < 0)
        {
            start = stationIdx + 1;
            gasTank = 0;
        }
    }

    return start;
}

// Brute Force
int canCompleteCircuitBF(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();

    for (int start = 0; start < n; start++)
    {
        int gasTank = 0;
        int station = start;
        for (station = start; station < n + start; station++)
        {
            gasTank += gas[station % n] - cost[station % n];

            if (gasTank < 0)
                break;
        }

        if (station == n + start && gasTank >= 0)
            return start;
    }

    return -1;
}