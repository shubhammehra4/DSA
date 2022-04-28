#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem
{
    unordered_map<int, pair<string, int>> travelStart; // "id" : [ startStation, timeIn]
    unordered_map<string, pair<int, int>> stats;       // "station1-station2" : [duration, tripCnt]

public:
    void checkIn(int id, string startStation, int timeIn)
    {
        travelStart[id] = {startStation, timeIn};
    }

    void checkOut(int id, string endStation, int timeOut)
    {
        const auto &[startStation, timeIn] = travelStart[id];
        auto &[totalDuration, tripsCnt] = stats[startStation + "-" + endStation];

        totalDuration += timeOut - timeIn;
        tripsCnt++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        auto [totalDuration, tripsCnt] = stats[startStation + "-" + endStation];
        return (double)totalDuration / tripsCnt;
    }
};
