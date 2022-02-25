#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
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

    vector<int> ordering;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        ordering.push_back(node);

        for (auto neighbor : adjLists[node])
        {
            inDegree[neighbor] -= 1;

            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    if (ordering.size() != numCourses)
        return {};

    return ordering;
}

// using vector instead of a queue
// because i will keep on incrementing no need to pop of the nodes that have been processed
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjLists(numCourses);
    vector<int> inDegree(numCourses, 0);

    for (auto &edge : prerequisites)
    {
        adjLists[edge[1]].push_back(edge[0]);
        inDegree[edge[0]]++;
    }

    vector<int> ordering;
    for (int i = 0; i < numCourses; i++)
        if (inDegree[i] == 0)
            ordering.push_back(i);

    for (int i = 0; i < ordering.size(); i++)
    {
        for (auto neighbor : adjLists[ordering[i]])
        {
            inDegree[neighbor] -= 1;

            if (inDegree[neighbor] == 0)
                ordering.push_back(neighbor);
        }
    }

    if (ordering.size() != numCourses)
        return {};

    return ordering;
}