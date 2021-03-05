#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start, end;
};

bool compareInterval (Interval i1, Interval i2)
{
    return (i1.end < i2.end);
}

void intervalSchedule (Interval arr[], int n) // Naive Approach
{
    int st[n];

    for (int i = 0; i < n; i++)
        st[i] = arr[i].start;

    int end = arr[0].end;
    vector<int> res;
    res.push_back (0);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (st[j] >= end)
            {
                res.push_back (j);
                end = arr[j].end;
                break;
            }
        }
    }

    for (auto i = res.begin(); i != res.end(); i++)
    {
        cout << arr[*i].start << " " << arr[*i].end << endl;
    }
}


int main()
{
    Interval arr[]
    = { { 0, 6 }, { 7, 8 }, { 0, 1 }, { 2, 3 }, {4, 5}, {6, 9}, {0, 3}, {4, 6}, {6, 7}};
    int n = sizeof (arr) / sizeof (arr[0]);
    sort (arr, arr + n, compareInterval);
    intervalSchedule (arr, n);
    return 0;
}