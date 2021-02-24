#include <bits/stdc++.h>
using namespace std;

void leftRotateStore (int arr[], int n, int d)
{
    int temp[d];

    for (int i = 0; i < d; i++)
        temp[i] = a[i];

    for (int i = 0; i < n - d; i++)
        a[i] = a[i + d];

    for (int i = n - 1 - d, j = 0; i < n; i++, j++)
        a[i] = temp[j];
}

void leftRotatebyOne (int arr[], int n)
{
    int temp = arr[0], i;

    for (i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];

    arr[i] = temp;
}

void leftRotate (int arr[], int d, int n)
{
    d = d % n;
    int g_c_d = __gcd (d, n);

    for (int i = 0; i < g_c_d; i++)
    {
        int temp = arr[i];
        int j = i;

        while (1)
        {
            int k = j + d;

            if (k >= n)
                k = k - n;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }

        arr[j] = temp;
    }
}
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int d;  //rotate d elements
    cin >> d;

    for (int i = 0; i < d; i++)
        leftRotatebyOne (a, 10);    //O(n*d)

    leftRotateStore (a, 10, 2);     //O(n)
    leftRotate (a, 2, 10);          //O(n)
}