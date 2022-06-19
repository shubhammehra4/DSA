#include <bits/stdc++.h>
using namespace std;

// priority queue
int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    int n = size(heights);
    priority_queue<int, vector<int>, greater<int>> pq; // pq -> higher jumps for ladders

    for (int i = 0; i < n - 1; i++)
    {
        int diff = heights[i + 1] - heights[i];
        if (diff > 0)
            pq.push(diff);

        if (size(pq) > ladders)
        {
            bricks -= pq.top();
            pq.pop();
        }

        if (bricks < 0)
            return i;
    }

    return n - 1;
}