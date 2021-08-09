/*
We start at some node in a directed graph, and every turn, we walk 
along a directed edge of the graph. If we reach a terminal node 
(that is, it has no outgoing directed edges), we stop.

We define a starting node to be safe if we must eventually walk to a 
terminal node. More specifically, there is a natural number k, so that 
we must have stopped at a terminal node in less than k steps for any 
choice of where to walk.

Return an array containing all the safe nodes of the graph. The answer should 
be sorted in ascending order.
*/
#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> &graph, int src, vector<int> &s)
{
    s[src] = 0;

    for (auto &i : graph[src])
    {
        if (s[i] == 1)
            continue;
        if (s[i] == 0 || isCycle(graph, i, s))
            return true;
    }

    s[src] = 1;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    vector<int> s(graph.size(), -1);
    // -1 - unvisited
    // 0 - unsafe
    // 1 - safe

    for (int i = 0; i < graph.size(); i++)
        if (s[i] == -1)
            isCycle(graph, i, s);

    vector<int> safe;
    for (int i = 0; i < graph.size(); i++)
        if (s[i] == 1)
            safe.push_back(i);

    return safe;
}

int main()
{

    return 0;
}