#include <bits/stdc++.h>
using namespace std;

int colorfulNumber(int A)
{
    vector<int> arr;
    while (A)
    {
        arr.push_back(A % 10);
        A = A / 10;
    }

    if (arr.size() == 1)
        return 1;

    unordered_map<int, int> map;
    // Find Duplicates
    for (int i = 0; i < arr.size(); i++)
    {
        if (map.find(arr[i]) == map.end())
            map[arr[i]] = 1;
        else
            return 0;
    }

    long int mul = 1, x = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= 4)
            mul *= arr[i];
        else
        {
            mul = 1;
            x = i + 1;
        }

        if (mul > 9)
        {
            mul /= arr[x];
            x + 1;
        }

        if ((map[mul] == 1 && mul != arr[i]) || arr[i] == 1 || arr[i] == 0)
            return 0;
    }

    return 1;
}

int main()
{

    return 0;
}