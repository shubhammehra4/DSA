#include <bits/stdc++.h>
using namespace std;

// stack
int calPoints(vector<string> &ops)
{
    vector<int> record;

    for (auto op : ops)
    {
        if (op == "C")
            record.pop_back();
        else if (op == "D")
            record.push_back(2 * record.back());
        else if (op == "+")
            record.push_back(rbegin(record)[0] + rbegin(record)[1]);
        else
            record.push_back(stoi(op));
    }

    return accumulate(begin(record), end(record), 0);
}