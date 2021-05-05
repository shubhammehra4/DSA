#include <bits/stdc++.h>
using namespace std;

// Similar to Job Sequencing in DP
// this is slot based

struct Job
{
    string id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n, int total)
{
    sort(arr, arr + n, comparison);
    vector<int> result;
    vector<bool> slot(total, false);
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(total, arr[i].dead) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                result.push_back(i);
                slot[j] = true;
                profit += arr[j].profit;
                break;
            }
        }
    }

    for (auto i : result)
        cout << arr[i].id << " ";
    cout << "\nProfit: " << profit;
}

int main()
{
    Job arr[] = {{"j1", 3, 35}, {"j2", 4, 30}, {"j3", 4, 25}, {"j4", 2, 20}, {"j5", 3, 15}, {"j6", 1, 12}, {"j7", 2, 5}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printJobScheduling(arr, n, 4);
    return 0;
}
