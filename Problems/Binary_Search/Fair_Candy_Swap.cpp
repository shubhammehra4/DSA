/*
Alice and Bob have a different total number of candies. 
You are given two integer arrays aliceSizes and bobSizes where 
aliceSizes[i] is the number of candies of the ith box of candy 
that Alice has and bobSizes[j] is the number of candies of the 
jth box of candy that Bob has.

Since they are friends, they would like to exchange one candy box each 
so that after the exchange, they both have the same total amount of candy. 
The total amount of candy a person has is the sum of the number of candies 
in each box they have.

Return an integer array answer where answer[0] is the number of candies 
in the box that Alice must exchange, and answer[1] is the number of candies 
in the box that Bob must exchange. If there are multiple answers, you may 
return any one of them. It is guaranteed that at least one answer exists.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> fairCandySwap(vector<int> &alice, vector<int> &bob)
{
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());

    int sumalice = accumulate(alice.begin(), alice.end(), 0);
    int sumbob = accumulate(bob.begin(), bob.end(), 0);

    int z = (sumbob - sumalice) / 2;

    for (auto x : alice)
    {
        int i = lower_bound(bob.begin(), bob.end(), z + x) - bob.begin();

        if (bob[i] == z + x)
            return {x, z + x};
    }

    return {};
}

int main()
{

    return 0;
}