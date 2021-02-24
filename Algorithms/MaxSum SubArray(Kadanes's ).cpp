#include <bits/stdc++.h>
using namespace std;

void maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0, 
       start =0, end = 0, s=0; 
    for (int i=0; i< size; i++ ) 
    { 
        max_ending_here += a[i]; 
        if (max_so_far < max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        }
        if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    } 
    cout << "Maximum contiguous sum is "<< max_so_far << endl; 
    cout << "Starting index "<< start<< endl << "Ending index "<< end ; 
} 
int main()
{
    int a[] = {1,5,6,8,-4,3,5,12,13,0,-1,19,-9,-5,15,10,5,4,1,7,3,8,-3,5,18,-9,1,3};
    maxSubArraySum(a,12);
}