#include <bits/stdc++.h>
using namespace std;

// Each job takes a single unit of time
struct Job
{
    string id;
    int deadline;
    int profit;
};

pair<vector<string>, int> jobSequencing(vector<Job> jobs)
{
    int n = jobs.size();
    sort(begin(jobs), end(jobs), [](auto a, auto b) -> bool
         { return a.profit > b.profit; });

    int totalProfit = 0;
    vector<int> res;
    vector<int> slotAssigned(n, false);

    for (int jIdx = 0; jIdx < n; jIdx++)
    {
        for (int slot = min(n, jobs[jIdx].deadline) - 1; slot >= 0; slot--)
        {
            if (slotAssigned[slot] == false)
            {
                res.push_back(jIdx);
                totalProfit += jobs[jIdx].profit;
                slotAssigned[slot] = true;
                break;
            }
        }
    }

    vector<string> scheduledJobs;
    for (auto jIdx : res)
        scheduledJobs.push_back(jobs[jIdx].id);

    return {scheduledJobs, totalProfit};
}