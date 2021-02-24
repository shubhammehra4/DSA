#include <bits/stdc++.h>
using namespace std;

int localMinUtil (int arr[], int low, int high, int n)
{
    int mid = (low + high) / 2 ;

    if ( (mid == 0 || arr[mid - 1] > arr[mid]) && (mid == n - 1 || arr[mid + 1] > arr[mid]) )
        return mid;
    else if (mid > 0 && arr[mid - 1] < arr[mid])
        return localMinUtil (arr, low, (mid - 1), n);
    else
        return localMinUtil (arr, (mid + 1), high, n);
}

int localMin (int arr[], int n)
{
    return localMinUtil (arr, 0, n - 1, n);
}
int main()
{
    int arr[] = {4, 3, 1, 14, 16, 40};
    int n = sizeof (arr) / sizeof (arr[0]);
    printf ("Index of a local minima is %d", localMin (arr, n) );
    return 0;
}