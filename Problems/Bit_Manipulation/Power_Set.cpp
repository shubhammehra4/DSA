#include <bits/stdc++.h>
using namespace std;

void printPowerSet(vector<int> set)
{
    int n = set.size();
    vector<int> subset;
    vector<vector<int>> p_set;
    /*set_size of power set of a set with set_size
    n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, n);

    /*Run from counter 000..0 to 111..1*/
    for (int counter = 0; counter < pow_set_size; counter++)
    {
        for (int j = 0; j < n; j++)
        {
            /* Check if jth bit in the counter is set
            If set then print jth element from set */
            if (counter & (1 << j))
                subset.push_back(set[j]);
        }
        p_set.push_back(subset);
        subset.clear();
    }
}

int main()
{
    return 0;
}