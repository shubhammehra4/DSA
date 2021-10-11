#include <bits/stdc++.h>
using namespace std;
/*
    Your task to check whether it is possible to construct a given array of integers 
    from a bunch of given pieces.

    More formally, you are given an array of distinct non-negative integers arr and 
    an array of integer arrays pieces. Your task is to check whether it is possible to 
    arrange the arrays of pieces in such a way that they can be concatenated to form an 
    array equal to arr (containing all the same elements in the same order).
*/

bool shuffleThePieces(vector<int> a, vector<vector<int>> p)
{
    unordered_map<int, vector<int>> m;

    for (auto i : p)
        m[i[0]] = i;

    int n = a.size();
    int i = 0;
    vector<int> tmp;
    int cnt = 0;
    while (i < n)
    {
        if (m.find(a[i]) == m.end())
            return false;

        tmp = m[a[i]];
        int j = 0;
        while (j < tmp.size() && i < n)
        {
            if (a[i] == tmp[j])
                i++, j++, cnt++;
            else
                return false;
        }
    }

    return cnt == n;
}

int main()
{
    return 0;
}