#include <bits/stdc++.h>
using namespace std;

int minFlipsMonoIncr(string s)
{
    int flips = 0, counter = 0;
    for (auto c : s)
    {
        if (c == '1')
            counter++;
        else
            flips++;

        flips = min(flips, counter);
    }

    return flips;
}

int main()
{
    return 0;
}