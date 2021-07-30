#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    int n = s.size();
    unordered_map<char, int> freq;
    char max_freq = s[0];

    for (char c : s)
    {
        freq[c]++;
        if (freq[c] > freq[max_freq])
            max_freq = c;
    }

    if (freq[max_freq] > (n + 1) / 2)
        return "";

    int i = 0;
    while (freq[max_freq])
    {
        s[i] = max_freq;
        i += 2;
        freq[max_freq]--;
    }

    for (auto f : freq)
    {
        while (f.second)
        {
            if (i >= n)
                i = 1;
            s[i] = f.first;
            f.second--;
            i += 2;
        }
    }

    return s;
}

int main()
{

    return 0;
}