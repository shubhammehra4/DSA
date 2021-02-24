#include <bits/stdc++.h>
using namespace std;

int DivideAlgo(int a[5][5],int n,int l ,int r)
{
    int found=0;
    int m=(l+r)/2;
    int min=a[m][0];
    if( a[m][0] < a[m-1][0] && a[m][0] < a[m+1][0] && a[m][0] < a[m][1] )
    {
        found = 1;
        return a[m][0];
    }
    else if ( a[m][n-1] < a[m-1][n-1] && a[m][n-1] < a[m+1][n-1] && a[m][n-1] < a[m][n-2] )
    {
        found = 1;
        return a[m][n-1];
    }
    else
    {
        for (int j=1;j<n-1;j++)
        {
            if ( a[m][j] < a[m-1][j] && a[m][j] < a[m+1][j] && a[m][j]< a[m][j+1] && a[m][j] < a[m][j-1])
            {
                found = 1;
                return a[m][j];
            }
            if(a[m][j]<min)
                min=a[m][j];
        }
    }
    if(a[m+1][min] < a[m][min])
        return DivideAlgo(a,5,m+1,n-1);
    else
        return DivideAlgo(a,5,0,m-1);
}

int main()
{
    int a[5][5] ={{1,5,7,3,6},{18,2,4,8,9},{21,13,14,17,22},{24,25,20,11,10},{12,15,16,19,23}};
    
    int LocalMinima = DivideAlgo(a,5);
    cout<<LocalMinima;
    
    return 0;
}
