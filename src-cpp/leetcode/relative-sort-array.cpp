#include <bits/stdc++.h>
using namespace std;

// vector as hashmap
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> idxMap(1001, 0);
    iota(begin(idxMap), end(idxMap), 1000);
    for (int i = 0; i < arr2.size(); i++)
        idxMap[arr2[i]] = i;

    sort(begin(arr1), end(arr1),
         [&idxMap](const int a, const int b) -> bool
         {
             return idxMap[a] < idxMap[b];
         });

    return arr1;
}

// hash map (brute-force)
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    unordered_map<int, int> idxMap;
    for (int i = 1; i <= arr2.size(); i++)
        idxMap[arr2[i - 1]] = i;

    sort(begin(arr1), end(arr1),
         [&idxMap](const int a, const int b) -> bool
         {
             if (idxMap[a] != 0 && idxMap[b] != 0)
                 return idxMap[a] < idxMap[b];
             else if (idxMap[b] != 0)
                 return false;
             else if (idxMap[a] != 0)
                 return true;

             return a < b;
         });

    return arr1;
}