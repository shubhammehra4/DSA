#include <bits/stdc++.h>
using namespace std;

bool winnerOfGame(string colors)
{
    int n = colors.size();
    int aliceTurns = 0;
    int bobTurns = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1])
        {
            if (colors[i] == 'A')
                aliceTurns++;
            else
                bobTurns++;
        }
    }

    return aliceTurns > bobTurns;
}

bool winnerOfGame(string colors)
{
    int n = colors.size();
    int aliceTurns = 0;
    int bobTurns = 0;
    int i = 0;

    while (i < n)
    {
        auto color = colors[i];
        int cnt = 0;

        while (i < n && color == colors[i])
            i++, cnt++;

        if (color == 'A')
            aliceTurns += max(0, cnt - 2);
        else
            bobTurns += max(0, cnt - 2);
    }

    return aliceTurns > bobTurns;
}

// unoptimised
// naive
bool winnerOfGame(string colors)
{
    int n = colors.size();
    if (n < 3)
        return false;

    int aliceTurns = 0;
    int bobTurns = 0;

    int cnt = 0;
    for (auto color : colors)
    {
        if (color == 'A')
            cnt++;
        else
        {
            if (cnt > 2)
                aliceTurns += cnt - 2;
            cnt = 0;
        }
    }

    if (cnt > 2)
        aliceTurns += cnt - 2;

    cnt = 0;

    for (auto color : colors)
    {
        if (color == 'B')
            cnt++;
        else
        {
            if (cnt > 2)
                bobTurns += cnt - 2;
            cnt = 0;
        }
    }

    if (cnt > 2)
        bobTurns += cnt - 2;

    return aliceTurns > bobTurns;
}