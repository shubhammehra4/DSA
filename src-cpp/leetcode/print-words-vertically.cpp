#include <bits/stdc++.h>
using namespace std;

vector<string> printVertically(string s)
{
    istringstream ss(s);
    vector<string> words;

    int maxSize = -1;
    string word;
    while (ss >> word)
    {
        maxSize = max(maxSize, (int)word.size());
        words.push_back(word);
    }

    vector<string> res(maxSize);
    for (auto i = 0; i < maxSize; ++i)
    {
        for (auto j = 0; j < words.size(); ++j)
        {
            if (i < words[j].size())
                res[i] += words[j][i];
            else
                res[i] += " ";
        }

        while (res[i].back() == ' ')
            res[i].pop_back();
    }

    return res;
}