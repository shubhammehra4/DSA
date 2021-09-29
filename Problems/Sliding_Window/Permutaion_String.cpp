#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    if (n > m)
        return false;

    vector<int> s1_freq(26, 0), s2_freq(26, 0);

    int i = 0;
    for (; i < n; i++)
    {
        // compute the frequency of each char for the first window
        ++s1_freq[s1[i] - 'a'];
        ++s2_freq[s2[i] - 'a'];
    }

    if (s1_freq == s2_freq)
        return true;

    // search the remaining windows
    for (; i < m; i++)
    {
        // remove the first char of current window and add the current char
        --s2_freq[s2[i - n] - 'a'];
        ++s2_freq[s2[i] - 'a'];
        if (s1_freq == s2_freq)
            return true;
    }
    return false;
}

int main()
{
    return 0;
}