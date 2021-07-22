#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";

    string res = "";
    int k = 0;
    int ptr = 0;
    int carry = 0;

    for (int i = num1.length() - 1; i >= 0; i--)
    {
        ptr = k++;
        for (int j = num2.length() - 1; j >= 0; j--)
        {
            int num = (num1[i] - '0') * (num2[j] - '0') + carry;

            if (ptr == 0 || ptr >= res.length())
                res += to_string(num % 10);
            else if (ptr < res.length())
            {
                num += (res[ptr] - '0');
                res[ptr] = '0' + num % 10;
            }

            carry = num / 10;
            ptr++;
        }
        if (carry)
            res += '0' + carry;

        carry = 0;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{

    return 0;
}