#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
// Hamiltonian Cycle - Visit every node only once

// generates all the permutations of bit sets of size n with r bits set
vector<int> combinations(int r, int n)
{
    vector<int> subsets;
    combinations(0, 0, r, n, subsets);
    return subsets;
}

void combinations(int set, int at, int r, int n, vector<int> &subsets)
{
    int elementsToPick = n - at;
    if (elementsToPick < r)
        return;

    if (r == 0)
        subsets.push_back(set);
    else
    {
        for (int i = at; i < n; i++)
        {
            set |= 1 << i; // include this element

            combinations(set, i, r - 1, n, subsets);

            set &= ~(1 << i); // exclude it to backtrack
        }
    }
}

// returns true if ith bit in subset is not set
bool notIn(int i, int subset)
{
    return (1 << i) & subset == 0;
}

auto travellingSalesmanTour(vector<vector<int>> &adjMatrix, int start)
{
    int n = adjMatrix.size();
    vector<vector<int>> memo(n, vector<int>(1 << n, -1));
    const int endState = (1 << n) - 1; // (2^n) -1

    // setup
    for (int i = 0; i < n; i++)
        if (i != start)
            memo[i][1 << start | 1 << i] = adjMatrix[start][i];
    //      1 << start | 1 << i -> is a bitmask with pos i and start set

    // solve
    // r -> no. of nodes in the partial tour
    for (int r = 3; r < n; r++)
    {
        for (auto subset : combinations(r, n))
        {
            if (notIn(start, subset)) // start should be present
                continue;

            for (int next = 0; next < n; next++) // target node
            {
                if (next == start || notIn(next, subset))
                    continue;

                int subsetWithoutNext = subset ^ (1 << next);
                int minDistance = INF;

                // end here represents the end node of the partial tour which will point to the next node
                for (int end = 0; end < n; end++)
                {
                    if (end == start || end == next || notIn(end, subset))
                        continue;

                    int newDistance = memo[end][subsetWithoutNext] + adjMatrix[end][next];

                    if (newDistance < minDistance)
                        minDistance = newDistance;
                }

                memo[next][subset] = minDistance;
            }
        }
    }

    // findMinCost
    int minTourCost = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (i != start)
        {
            int tourCost = memo[i][endState] + adjMatrix[i][start];
            minTourCost = min(minTourCost, tourCost);
        }
    }

    // findTourPath
    vector<int> tour;
    int lastIndex = start; // end of the tour is start
    int state = endState;

    tour.push_back(start);

    for (int i = 1; i < n; i++)
    {
        int index = -1; // idx of best next node
        for (int j = 0; j < n; j++)
        {
            if (j == start || notIn(j, state))
                continue;

            if (index == -1)
                index = j;

            int prevDist = memo[index][state] + adjMatrix[index][lastIndex];
            int newDist = memo[j][state] + adjMatrix[j][lastIndex];

            if (newDist < prevDist)
                index = j;
        }

        tour.push_back(index);
        state = state ^ (1 << index); // marking it as visited
        lastIndex = index;
    }
    tour.push_back(start);
    reverse(begin(tour), end(tour));

    return make_pair(minTourCost, tour);
}