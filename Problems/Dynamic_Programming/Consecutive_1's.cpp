#include <bits/stdc++.h>
using namespace std;

/*
Let a[i] be the number of binary strings of length i which do not 
contain any two consecutive 1’s and which end in 0. Similarly, 
let b[i] be the number of such strings which end in 1. We can append 
either 0 or 1 to a string ending in 0, but we can only append 0 to a 
string ending in 1. This yields the recurrence relation: 

a[i] = a[i - 1] + b[i - 1]
b[i] = a[i - 1] 
*/

// count is actually (n+2)’th Fibonacci number for n >= 1
int countStrings(int n)
{
    int a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + b[i - 1];
        b[i] = a[i - 1];
    }
    return a[n - 1] + b[n - 1];
}

int main()
{
    cout << countStrings(18);

    return 0;
}