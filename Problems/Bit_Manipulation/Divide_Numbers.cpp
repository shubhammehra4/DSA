#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    int sign = ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    int quotient = 0;
    while (dividend >= divisor)
    {
        dividend -= divisor;
        ++quotient;
    }

    return sign * quotient;
}

int divideBit(long long dividend, long long divisor)
{
    long long int divi = dividend;
    long long int dis = divisor;

    int sign = ((divi < 0 && dis < 0) || (divi > 0 && dis > 0)) ? 1 : -1;
    divi = abs(divi);
    dis = abs(dis);

    long long int ans = 0;
    while (divi >= dis)
    {
        //we find the maximum multiple of divisor which we can subtract with dividend
        long long int temp = dis;
        int po = 0;
        while (divi >= temp)
        {
            temp = temp << 1ll;
            po++;
        }

        temp = temp >> 1ll;
        po--;

        divi -= temp;
        ans += 1ll << po;
    }

    ans *= sign;
    return (ans > INT_MAX) ? INT_MAX : ans;
}

int main()
{
    return 0;
}