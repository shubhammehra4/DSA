#include <bits/stdc++.h>
using namespace std;

int getNext(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += pow(n % 10, 2);
        n /= 10;
    }

    return sum;
}

// cycle detection
bool isHappy(int n)
{
    int slow = n;
    int fast = getNext(n);

    while (fast != 1 && slow != fast)
    {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }

    return fast == 1;
}

// recursive & mathematical property
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