/* 
A happy number is a number defined by the following process:

Starting with any positive integer, replace the number 
by the sum of the squares of its digits.

Repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1.

Those numbers for which this process ends in 1 are happy.
*/
#include <bits/stdc++.h>
using namespace std;

bool isHappy(int n)
{
    int sum = 0;

    while (n != 0)
    {
        sum += pow(n % 10, 2);
        n /= 10;
    }

    if (sum == 4)
        return false;

    if (sum != 1)
        return isHappy(sum);

    return true;
}

int main()
{

    return 0;
}