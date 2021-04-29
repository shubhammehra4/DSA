#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(string arr[], int n)
{
    if (n == 0)
        return "";

    if (n == 1)
        return arr[0];

    sort(arr, arr + n);
    int end = min(arr[0].size(), arr[n - 1].size());
    string first = arr[0], last = arr[n - 1];
    int i = 0;

    while (i < end && first[i] == last[i])
        i++;

    return first.substr(0, i);
}

int main()
{
    string arr[] = {"geeksforgeeks", "geeks", "geek", "geeker"};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestCommonPrefix(arr, n);
    return (0);
}
