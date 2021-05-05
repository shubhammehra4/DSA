#include <bits/stdc++.h>
using namespace std;

// Similar to Job Sequencing in DP but in unweighted

struct Interval
{
    int start, end;
};

bool compareInterval(Interval i1, Interval i2)
{
    return (i1.end < i2.end);
}

void intervalSchedule(Interval arr[], int n) // Naive Approach
{
    int st[n];

    for (int i = 0; i < n; i++)
        st[i] = arr[i].start;

    int end = arr[0].end;
    vector<int> res;
    res.push_back(0);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (st[j] >= end)
            {
                res.push_back(j);
                end = arr[j].end;
                break;
            }
        }
    }

    for (auto i = res.begin(); i != res.end(); i++)
    {
        cout << arr[*i].start << " - " << arr[*i].end << endl;
    }
}

void intervalScheduleOpti(Interval arr[], int n)
{
    int st[n];

    for (int i = 0; i < n; i++)
        st[i] = arr[i].start;

    cout << "Jobs are:" << endl;
    cout << arr[0].start << " - " << arr[0].end << endl;
    int i = arr[0].end;

    for (int j = 1; j < n; j++)
    {
        if (st[j] >= i)
        {
            cout << arr[j].start << " - " << arr[j].end << endl;
            i = arr[j].end;
        }
    }
}

int main()
{
    Interval arr[] = {{0, 6}, {7, 8}, {0, 1}, {2, 3}, {4, 5}, {6, 9}, {0, 3}, {4, 6}, {6, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, compareInterval); // Sort According to Ending
    intervalSchedule(arr, n);
    intervalScheduleOpti(arr, n);
    return 0;
}