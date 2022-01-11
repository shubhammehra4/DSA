#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;

    return -1;
}
int main()
{
    int n = 10;
    int a[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int y = LinearSearch(a, n, 10);

    if (y == -1)
    {
        cout << "Element not present\n";
    }

    else
        cout << "Element is at index " << y + 1 << "\n";

    return 0;
}