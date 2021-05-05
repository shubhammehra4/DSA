#include <bits/stdc++.h>
using namespace std;

// Similar to Interval Scheduling in Greedy
// & Job Sequencing in Greedy
struct Job
{
    string id;
    int start;
    int dead;
    int profit;
};

bool jobComparison(Job s1, Job s2)
{
    return (s1.dead < s2.dead);
}

int latestNonConflict(Job arr[], int i) // Optimised by Binary Search
{
    int l = 0, r = i - 1, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (arr[mid].dead <= arr[i].start)
        {
            if (arr[mid + 1].dead <= arr[i].start)
                l = mid + 1;
            else
                return mid;
        }
        else if (arr[mid].dead > arr[i].start)
            r = mid - 1;
    }

    return -1;
}

int findMaxProfit(Job arr[], int n)
{
    sort(arr, arr + n, jobComparison);

    int *table = new int[n];
    table[0] = arr[0].profit;

    for (int i = 1; i < n; i++)
    {
        int inclProf = arr[i].profit;
        int l = latestNonConflict(arr, i);
        if (l != -1)
            inclProf += table[l];

        table[i] = max(inclProf, table[i - 1]);
    }

    int result = table[n - 1];
    delete[] table;

    return result;
}

int main()
{
    Job arr[] = {{"j1", 3, 10, 20}, {"j2", 1, 2, 50}, {"j3", 6, 19, 100}, {"j4", 2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxProfit(arr, n);
    return 0;
}
