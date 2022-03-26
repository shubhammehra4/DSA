#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    sort(begin(people), end(people));
    int n = people.size();
    int i = 0, j = n - 1;
    int res = 0;

    while (i <= j)
    {
        res++;

        if (people[i] + people[j] <= limit)
            i++;
        j--;
    }

    return res;
}