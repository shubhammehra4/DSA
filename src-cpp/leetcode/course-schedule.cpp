#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjLists(numCourses);
    vector<int> inDegree(numCourses, 0);

    for (auto &edge : prerequisites)
    {
        adjLists[edge[1]].push_back(edge[0]);
        inDegree[edge[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (inDegree[i] == 0)
            q.push(i);

    int compltetedCourses = 0;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        compltetedCourses++;

        for (auto neighbor : adjLists[node])
        {
            inDegree[neighbor] -= 1;

            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return compltetedCourses == numCourses;
}

// Unoptimised top-sort
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> inDegree(numCourses, 0);

    for (auto &edge : prerequisites)
        inDegree[edge[0]]++;

    queue<int> q;

    for (int i = 0; i < numCourses; i++)
        if (inDegree[i] == 0)
            q.push(i);

    int compltetedCourses = 0;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        compltetedCourses++;

        for (auto &edge : prerequisites)
            if (edge[1] == node)
            {
                inDegree[edge[0]]--;
                if (inDegree[edge[0]] == 0)
                    q.push(edge[0]);
            }
    }

    return compltetedCourses == numCourses;
}

// smart
// using vector instead of a queue
// because i will keep on incrementing no need to pop of the nodes that have been processed
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjLists(numCourses);
    vector<int> inDegree(numCourses, 0);

    for (auto &edge : prerequisites)
    {
        adjLists[edge[1]].push_back(edge[0]);
        inDegree[edge[0]]++;
    }

    vector<int> q;
    for (int i = 0; i < numCourses; i++)
        if (inDegree[i] == 0)
            q.push_back(i);

    for (int i = 0; i < q.size(); i++)
    {
        for (auto neighbor : adjLists[q[i]])
        {
            inDegree[neighbor] -= 1;

            if (inDegree[neighbor] == 0)
                q.push_back(neighbor);
        }
    }

    return q.size() == numCourses;
}
