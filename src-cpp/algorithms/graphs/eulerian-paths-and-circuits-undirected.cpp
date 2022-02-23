#include <bits/stdc++.h>
using namespace std;

/**
 * variant : "path" | "circuit"
 */
auto findEulerianPath(vector<vector<int>> &adjLists, int v, int e, string variant = "path")
{
    vector<int> degree(v, 0);
    list<int> path;

    //  countDegree
    [&degree, &adjLists]() -> void
    {
        for (auto edges : adjLists)
            for (auto edge : edges)
                degree[edge]++;
    }();

    auto graphHasEulerianPath = [&degree, v]() -> bool
    {
        int oddDegreeNodes = 0;
        for (auto d : degree)
        {
            oddDegreeNodes += d % 2;
            if (oddDegreeNodes > 2)
                return false;
        }

        return true;
    };

    auto graphHasEulerianCircuit = [&degree, &adjLists, v]() -> bool
    {
        for (auto d : degree)
            if (d % 2 == 1)
                return false;

        return true;
    };

    if (variant == "path" && !graphHasEulerianPath())
        throw "No Eulerian path exists";
    else if (variant == "circuit" && !graphHasEulerianCircuit())
        throw "No Eulerian circuit exists";

    auto findStartNode = [&degree, v]() -> int
    {
        int start = 0;
        for (int i = 0; i < v; i++)
        {
            if (degree[i] % 2 == 1)
                return i;

            if (degree[i] > 0)
                start = i;
        }

        return start;
    };

    function<void(int)> dfs = [&degree, &adjLists, &path, &dfs](int at) -> void
    {
        while (degree[at] != 0)
        {
            auto nextEdge = adjLists[at][degree[at]];
            degree[at] -= 1;
            dfs(nextEdge);
        }
        path.push_front(at);
    };

    dfs(findStartNode());

    if (path.size() == e + 1) // The graph might be disconnected, in that case it's not possible to have an eulerian path
        return path;

    throw "Graph might be disconnected";
    return list<int>();
}