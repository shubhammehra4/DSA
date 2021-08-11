#include <bits/stdc++.h>
using namespace std;

bool canReorderDoubled(vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (auto i : arr)
        freq[i]++;

    sort(arr.begin(), arr.end());

    for (auto i : arr)
        if (freq[i] && freq[i * 2])
            freq[i]--, freq[i * 2]--;

    for (auto e : freq)
        if (e.second)
            return false;

    return true;
}

int main()
{

    return 0;
}