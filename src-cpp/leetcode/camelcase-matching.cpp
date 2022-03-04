#include <bits/stdc++.h>
using namespace std;

bool isMatch(const string &query, const string &pattern)
{
    int i = 0;
    int m = pattern.size();

    for (auto &c : query)
    {
        if (i < m && c == pattern[i])
            i++;
        else if (isupper(c))
            return false;
    }

    return i == m;
}

vector<bool> camelMatch(vector<string> &queries, string pattern)
{
    vector<bool> res;

    for (string &query : queries)
        res.push_back(isMatch(query, pattern));

    return res;
}

// brute-force
vector<bool> camelMatch(vector<string> &queries, string pattern)
{
    vector<bool> res;
    int m = pattern.size();

    for (auto query : queries)
    {
        int i = 0, j = 0;
        int n = query.size();

        while (i < n && j < m)
        {
            if (query[i] == pattern[j])
                i++, j++;
            else if (isupper(query[i]))
                break;
            else
                i++;
        }
        bool match = j == m;

        if (match)
        {
            for (; i < n; i++)
                if (isupper(query[i]))
                {
                    match = false;
                    break;
                }
        }

        res.push_back(match);
    }

    return res;
}