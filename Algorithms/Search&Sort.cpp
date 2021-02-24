#include<bits/stdc++.h>
#define fab(a,b,i) for(int i=a;i<b;i++)
using namespace std;

int stringlen (char a[])
{
    int cnt = 0, i = 0;

    while (a[i] != '\0')
    {
        cnt++;
        i++;
    }

    return cnt;
}

void conc (char *a, char *b)
{
    int len = stringlen (a);
    int i;

    for ( i = 0; b[i] != '\0'; i++)
    {
        a[i + len] = b[i];
    }

    a[i + len] = '\0';
}

void copystr (char *a, char *b)
{
    int i;

    for (i = 0; a[i] != '\0'; i++)
        b[i] = a[i];

    b[i] = '\0';
}

bool palin (char a[])
{
    int len = stringlen (a);

    for (int i = 0; i < len / 2; i++)
    {
        if (a[i] != a[len - i - 1])
            return false;
    }

    return true;
}

void rev (char *a)
{
    int len = stringlen (a);
    char p;

    for (int i = 0; i < len / 2; i++)
    {
        p = a[i];
        a[i] = a[len - 1 - i];
        a[len - i - 1] = p;
    }
}

void array_inserton (int arr[], int n)
{
    int i, j, k, val;
    //cout<<"input the indice where you want to insert";
    cin >> k;
    //cout<<endl<<"enter value";
    cin >> val;
    n = n + 1;

    for (int i = n; i >= k; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[k] = val;
}

void array_deletion (int arr[], int n)
{
    int i, k;
    //cout<<"enter the indice you want to delete ";
    cin >> k;
    k = k - 1;
    n = n - 1;

    for (i = k; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int linear_search (int arr[], int n, int x)
{
    int i;

    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;

    return -1;
}

int binarySearch (int arr[], int l, int r , int x)
{
    int mid = l + (r - l) / 2;

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x && arr[mid] < arr[r - 1])
        return binarySearch (arr, l, mid - 1, x);
    else if (arr[mid] < x && arr[mid] < arr[l])
        return binarySearch (arr, mid + 1, r, x);
    else
        return -1;
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort (int a[], int n)
{
    int i, j, flag;

    for (i = 0; i < n; i++)
    {
        flag = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap (&a[j], &a[j + 1]);
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}

void InsertionSort (int a[], int n)
{
    int i, j, x;

    for (i = 0; i < n; i++)
    {
        x = a[i];
        j = i - 1;

        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

void SelectionSort (int a[], int n)
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (a[j] < a[k])
                k = j;
        }

        swap (a[i], a[k]);
    }
}

int partition (int a[], int l, int h)
{
    int p = a[h];
    int i = l - 1, j;

    for (j = l; j < h; j++)
    {
        if (a[j] < p)
        {
            i++;
            swap (&a[i] , &a[j]);
        }
    }

    swap (&a[i + 1], &a[h]);
    return i + 1;
}
void QuickSort (int a[], int l, int h)
{
    int j;

    if (l < h)
    {
        j = partition (a , l , h);
        QuickSort (a , l , j - 1);
        QuickSort (a , j + 1 , h);
    }
}

void Merge (int a[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int temp[10005];

    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    for (; i <= mid; i++)
    {
        temp[k++] = a[i];
    }

    for (; j <= h; j++)
    {
        temp[k++] = a[j];
    }

    for (i = l; i <= h; i++)
    {
        a[i] = temp[i];
    }
}

void IMergeSort (int a[], int n)
{
    int i, j, mid, l, h, p;

    for (p = 2; p <= n; p *= 2)
    {
        for (i = 0; i + p - 1 < n; i += p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge (a , l , mid , h);
        }
    }

    if (p / 2 < n)
    {
        Merge (a , 0 , p / 2 - 1 , n - 1);
    }
}

int main()
{
    cout << "Enter length of the array :";
    int n;
    cin >> n;
    cout << "Enter elements of the array :";
    int arr[n], i;
    fab (0, n, i)
    {
        cin >> arr[i];
    }
    int ch = 100000;

    while (ch != 0)
    {
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Selection Sort\n";
        cout << "5. Bubble Sort\n";
        cout << "6. Merge Sort\n";
        cout << "7. Quick Sort\n";
        cout << "0. Exit\n";
        cin >> ch;

        switch (ch)
        {
            case 1 :
                cout << "Enter the element you want to search :";
                int x, y;
                cin >> x;
                y = linear_search (arr, n, x);

                if (y == -1)
                {
                    cout << "Element not present\n";
                }

                else
                    cout << "Element is at " << y + 1 << "position\n";

                break;

            case 2 :
                {
                    cout << "Enter the element you want to search :";
                    int x, y;
                    cin >> x;
                    y = binarySearch (arr, 0, n, x);

                    if (y == -1)
                    {
                        cout << "Element not present\n";
                    }

                    else
                        cout << "Element is at " << y + 1 << "position\n";

                    break;
                }

            case 3:
                {
                    int i;
                    InsertionSort (arr, n);
                    cout << "Sorted array is : ";
                    fab (0, n, i)
                    {
                        cout << arr[i] << " ";
                    }
                    cout << "\n";
                    break;
                }

            case 4:
                {
                    int i;
                    SelectionSort (arr, n);
                    cout << "Sorted array is : ";
                    fab (0, n, i)
                    {
                        cout << arr[i] << " ";
                    }
                    cout << "\n";
                    break;
                }

            case 5:
                {
                    int i;
                    BubbleSort (arr, n);
                    cout << "Sorted array is : ";
                    fab (0, n, i)
                    {
                        cout << arr[i] << " ";
                    }
                    cout << "\n";
                    break;
                }

            case 6:
                {
                    int i;
                    IMergeSort (arr, n);
                    cout << "Sorted array is : ";
                    fab (0, n, i)
                    {
                        cout << arr[i] << " ";
                    }
                    cout << "\n";
                    break;
                }

            case 7:
                {
                    int i;
                    QuickSort (arr, 0, n - 1);
                    cout << "Sorted array is : ";
                    fab (0, n, i)
                    {
                        cout << arr[i] << " ";
                    }
                    cout << "\n";
                    break;
                }
        }
    }

    return 0;
}