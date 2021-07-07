#include <bits/stdc++.h>
using namespace std;
int singleDigit(int num)
{
    return (num >= 0 && num < 10);
}

int util(int num, int *temp)
{
    if (singleDigit(num))
        return num == (*temp) % 10;

    if (!util(num / 10, temp))
        return 0;

    *temp /= 10;
    return (num % 10 == (*temp) % 10);
}
int isPalindrome(int A)
{
    if (A < 0)
        A = -A;

    int *temp = new int(A);
    return util(A, temp);
}

int main()
{
    int a = 6776;
    cout << isPalindrome(a);
    return 0;
}