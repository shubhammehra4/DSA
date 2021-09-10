#include <bits/stdc++.h>
using namespace std;

/*
Let the function f(s) be the frequency of the lexicographically smallest character in a non-empty string s. 
For example, if s = "dcce" then f(s) = 2 because the lexicographically smallest character is 'c', which has a frequency of 2.

You are given an array of strings words and another array of query strings queries. For each query queries[i], 
count the number of words in words such that f(queries[i]) < f(W) for each W in words.

Return an integer array answer, where each answer[i] is the answer to the ith query.

Constrinats :- Each word will not be longer than 10
*/

int getFreq(string &s)
{
    return count(begin(s), end(s), *min_element(begin(s), end(s)));
}

// For longer strings
// int getFreq(string &s)
// {
//     int a[26] = {0};
//     for (int i = 0; i < s.size(); i++)
//     {
//         a[s[i] - 'a']++;
//     }

//     for (int i = 0; i < 26; i++)
//     {
//         if (a[i] != 0)
//             return a[i];
//     }
//     return 0;
// }

vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
{
    vector<int> fr(12, 0);
    vector<int> ans;
    for (auto &w : words)
        fr[getFreq(w)]++;

    for (int i = 9; i >= 0; i--)
        fr[i] += fr[i + 1];

    for (auto &q : queries)
        ans.push_back(fr[getFreq(q) + 1]);

    return ans;
}

int main()
{
    return 0;
}