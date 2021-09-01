#include <bits/stdc++.h>
using namespace std;

/*
0 --> 0
1 --> 1
2 --> 1
3 --> 2
4 --> 1
5 --> 2
6 --> 2
7 --> 3
8 --> 1
9 --> 2
10 -> 2
*/

vector<int> countBits(int num)
{
    vector<int> res(num);
    res.push_back(0);
    if (num == 0)
        return res;

    for (int i = 1; i <= num; i++)
    {
        if (i % 2 == 0)
            res[i] = res[i / 2];
        else
            res[i] = res[i - 1] + 1;
    }
    return res;
}

int main()
{
    return 0;
}