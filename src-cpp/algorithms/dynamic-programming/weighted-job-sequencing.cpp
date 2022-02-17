#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int start;
    int end;
    int profit;
};

int previousNonConflictingJob(vector<Job> &arr, int i)
{
    int l = 0, r = i - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid].end <= arr[i].start)
        {
            if (arr[mid + 1].end <= arr[i].start)
                l = mid + 1;
            else
                return mid;
        }
        else
            r = mid - 1;
    }

    return -1;
}

int weightedJobProfit(vector<Job> jobs)
{
    sort(begin(jobs), end(jobs), [](const Job &j1, const Job &j2) -> bool
         { return j1.end < j2.end; });

    int n = jobs.size();
    vector<int> profit(n, 0);
    profit[0] = jobs[0].profit;

    for (int i = 1; i < n; i++)
    {
        int currProfit = jobs[i].profit;
        int jobIdx = previousNonConflictingJob(jobs, i);
        if (jobIdx != -1)
            currProfit += profit[jobIdx];

        profit[i] = max(currProfit, profit[i - 1]);
    }

    return profit.back();
}
