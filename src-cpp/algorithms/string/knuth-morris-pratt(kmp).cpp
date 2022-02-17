#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPSArray(string pattern)
{
    int m = pattern.size();
    vector<int> lps(m, 0);

    int i = 0;
    for (int j = 1; j < m; j++)
    {
        if (pattern[j] == pattern[i])
        {
            lps[j] = i + 1;
            i++;
        }
        else
        {
            i = i > 0 ? lps[i - 1] : lps[0];
            lps[j] = 0;
        }
    }

    return lps;
}

// Pattern Searching
vector<int> knuthMorrisPratt(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();

    vector<int> lps = buildLPSArray(pattern);
    vector<int> patternIndex;

    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
            j++, i++;

        if (j == m)
        {
            patternIndex.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    return patternIndex;
}