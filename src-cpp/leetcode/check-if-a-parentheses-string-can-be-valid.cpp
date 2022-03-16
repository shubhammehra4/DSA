#include <bits/stdc++.h>
using namespace std;

bool canBeValid(string s, string locked)
{
    auto validate = [&s, &locked](char op)
    {
        int n = s.size();
        int bal = 0, unlocked = 0;

        int start = op == '(' ? 0 : n - 1;
        int dir = op == '(' ? 1 : -1;

        for (int i = start; i >= 0 && i < n && unlocked + bal >= 0; i += dir)
            if (locked[i] == '1')
                bal += s[i] == op ? 1 : -1;
            else
                ++unlocked;

        return abs(bal) <= unlocked;
    };

    return s.size() % 2 == 0 && validate('(') && validate(')');
}