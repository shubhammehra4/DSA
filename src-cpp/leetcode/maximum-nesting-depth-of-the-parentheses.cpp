#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s)
{
    int depth = 0;
    int maxD = 0;

    for (auto c : s)
    {
        if (c == '(')
            depth += 1;
        else if (c == ')')
        {
            maxD = max(maxD, depth);
            depth -= 1;
        }
    }

    return maxD;
}