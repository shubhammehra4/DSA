#include <bits/stdc++.h>
using namespace std;

int JumpSearch (int a[], int n, int x)
{
    int step = sqrt (n);
    int base = 0;

    while (a[min (step, n) - 1] < x) // min as step could be graeter than n
    {
        base = step;
        step += sqrt (n);

        if (base >= n) return -1; // not present
    }

    while (a[base] < x)
    {
        base++;

        if (base == min (step, n) ) return -1; // not present
    }

    if (a[base] == x)
        return base;

    return -1;
}

int main()
{
    int n = 10;
    int a[n] = {1, 4, 5, 9, 14, 17, 20, 27, 34, 55}; // Sorted array
    int y = JumpSearch (a, 10, 17);

    if (y == -1)
    {
        cout << "Element not present\n";
    }

    else
        cout << "Element is at index " << y + 1 << "\n";

    return 0;
}