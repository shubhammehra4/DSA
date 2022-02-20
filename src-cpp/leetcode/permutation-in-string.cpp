#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    if (n > m)
        return false;

    vector<int> s1Freq(26, 0);
    vector<int> s2Freq(26, 0);

    for (int i = 0; i < n; i++)
    {
        ++s1Freq[s1[i] - 'a'];
        ++s2Freq[s2[i] - 'a'];
    }

    int count = 0;
    for (int j = 0; j < 26; j++)
        if (s1Freq[j] == s2Freq[j])
            count++;

    for (int i = n; i < m; i++)
    {
        auto l = s2[i - n] - 'a';
        auto r = s2[i] - 'a';

        if (count == 26)
            return true;

        s2Freq[r]++;
        s2Freq[l]--;

        if (s2Freq[r] == s1Freq[r])
            count++;
        else if (s2Freq[r] == s1Freq[r] + 1)
            count--;

        if (s2Freq[l] == s1Freq[l])
            count++;
        else if (s2Freq[l] == s1Freq[l] - 1)
            count--;
    }

    return count == 26;
}

// Alter
bool checkInclusion(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    if (n > m)
        return false;

    vector<int> s1Freq(26, 0);
    vector<int> s2Freq(26, 0);

    for (int i = 0; i < n; i++)
    {
        ++s1Freq[s1[i] - 'a'];
        ++s2Freq[s2[i] - 'a'];
    }

    if (s1Freq == s2Freq)
        return true;

    for (int i = n; i < m; i++)
    {
        auto l = s2[i - n] - 'a';
        auto r = s2[i] - 'a';

        s2Freq[r]++;
        s2Freq[l]--;

        if (s1Freq == s2Freq)
            return true;
    }

    return false;
}