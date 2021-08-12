#include <bits/stdc++.h>
using namespace std;

string cntSort(string s)
{
    int counter[26] = {0};
    for (char c : s)
        counter[c - 'a']++;

    string t;
    for (int c = 0; c < 26; c++)
        t += string(counter[c], c + 'a');

    return t;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;

    for (auto s : strs)
        m[cntSort(s)].push_back(s);

    for (auto e : m)
        res.push_back(e.second);

    return res;
}

int main()
{
    return 0;
}