/*
A magical string s consists of only '1' and '2' and obeys the following rules:

The string s is magical because concatenating the number of contiguous occurrences 
of characters '1' and '2' generates the string s itself.
The first few elements of s is s = "1221121221221121122……". 
If we group the consecutive 1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22 ......" 
and the occurrences of 1's or 2's in each group are "1 2 2 1 1 2 1 2 2 1 2 2 ......". 
You can see that the occurrence sequence is s itself.

Given an integer n, return the number of 1's in the first n number in the magical string s.
*/
#include <bits/stdc++.h>
using namespace std;

int magicalString(int n)
{
    if (n <= 0)
        return 0;
    if (n <= 3)
        return 1;

    int count = 0;
    vector<int> str = {1, 2, 2};
    int idx = 2;
    int digit = 1;
    while (str.size() < n)
    {
        if (str[idx] == 1)
            str.push_back(digit);
        else if (str[idx] == 2)
        {
            str.push_back(digit);
            str.push_back(digit);
        }

        digit = digit == 1 ? 2 : 1;
        idx++;
    }
    for (int x = 0; x < n; x++)
    {
        if (str[x] == 1)
            count++;
    }

    return count;
}

int main()
{

    return 0;
}