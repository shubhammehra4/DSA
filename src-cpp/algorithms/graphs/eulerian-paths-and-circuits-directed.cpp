#include <bits/stdc++.h>
using namespace std;

struct DirectedEdge
{
    int from;
    int to;
};

/**
 * variant : "path" | "circuit"
 */
auto findEulerianPath(vector<vector<DirectedEdge>> &adjLists, int v, int e, string variant = "path")
{
    vector<int> in(v, 0);
    vector<int> out(v, 0);
    list<int> path;

    //  countInOutDegree
    [&in, &out, &adjLists]() -> void
    {
        for (auto edges : adjLists)
            for (auto edge : edges)
                out[edge.from]++, in[edge.to]++;
    }();

    auto graphHasEulerianPath = [&in, &out, v]() -> bool
    {
        int startNodes = 0, endNodes = 0;

        for (int i = 0; i < v; i++)
        {
            if (abs(out[i] - in[i]) > 1)
                return false;

            if (out[i] - in[i] == 1)
                startNodes++;
            else if (in[i] - out[i] == 1)
                endNodes++;
        }

        return (startNodes == 0 && endNodes == 0) || (startNodes == 1 && endNodes == 1);
    };

    auto graphHasEulerianCircuit = [&in, &out, v]() -> bool
    {
        for (int i = 0; i < v; i++)
            if (out[i] != in[i])
                return false;

        return true;
    };

    if (variant == "path" && !graphHasEulerianPath())
        throw "No Eulerian path exists";
    else if (variant == "circuit" && !graphHasEulerianCircuit())
        throw "No Eulerian circuit exists";

    auto findStartNode = [&in, &out, v]() -> int
    {
        int start = 0;
        for (int i = 0; i < v; i++)
        {
            if (out[i] - in[i] == 1)
                return i;

            if (out[i] > 0)
                start = i;
        }

        return start;
    };

    function<void(int)> dfs = [&out, &adjLists, &path, &dfs](int at) -> void
    {
        while (out[at] != 0)
        {
            auto nextEdge = adjLists[at][out[at]];
            out[at] -= 1;
            dfs(nextEdge.to);
        }
        path.push_front(at);
    };

    dfs(findStartNode());

    if (path.size() == e + 1) // The graph might be disconnected, in that case it's not possible to have an eulerian path
        return path;

    throw "Graph might be disconnected";
    return list<int>();
}