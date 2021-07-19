/*
You are given a 1D integer array B containing A integers.

Count the number of ways to split all the elements of the 
array into 3 contiguous parts so that the sum of elements in each part is the same.

Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])
*/
#include <bits/stdc++.h>
using namespace std;

int Partitions(int A, vector<int> &B)
{
    int sum = 0;
    for (int i = 0; i < A; i++)
        sum += B[i];

    if (sum % 3 != 0)
        return 0;

    int sum13rd = sum / 3;
    int sum23rd = 2 * sum13rd;
    int currSum = 0;
    int g13rd = 0;
    int count = 0;
    for (int i = 0; i < A - 1; i++)
    {
        currSum += B[i];
        if (currSum == sum13rd)
            g13rd++;

        if (currSum == sum23rd)
            count += g13rd;
    }
    return count;
}

int main()
{
    return 0;
}