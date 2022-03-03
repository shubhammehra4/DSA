#include <bits/stdc++.h>
using namespace std;

// greedy
long long numberOfWeeks(vector<int> &milestones)
{
    int maxEle = *max_element(milestones.begin(), milestones.end());

    long long sum = accumulate(begin(milestones), end(milestones), 0LL);

    long long rest = sum - (long long)maxEle;

    if (rest >= maxEle)
        return sum;

    return rest * 2 + 1;
}

// max heap
// tle
long long numberOfWeeks(vector<int> &milestones)
{
    int n = size(milestones);
    if (n == 1)
        return 1;

    priority_queue<int> pq(begin(milestones), end(milestones));
    long long weeks = 0;

    while (pq.size() >= 2)
    {
        int task1 = pq.top();
        pq.pop();

        int task2 = pq.top();
        pq.pop();

        task1 -= 1;
        task2 -= 1;

        weeks += 2;

        if (task1 > 0)
            pq.push(task1);

        if (task2 > 0)
            pq.push(task2);
    }

    if (pq.size() > 0)
        weeks += 1;

    return weeks;
}
