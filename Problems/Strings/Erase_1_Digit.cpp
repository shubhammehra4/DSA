#include <bits/stdc++.h>
using namespace std;

/*
You are given three integers in the form of strings: firstnum, secondnum, and thirdnum. 
Your task is to check whether it is possible to erase at most one digit from firstnum, 
so that the resulting string contains at least one digit, has no leading zeros and the value 
of thirdnum is equal to the sum of the values of firstnum and secondnum.

Return true if it's possible, otherwise return false.
*/

// string addStrings(string s1, string s2)
// {
//     if (s1.length() < s2.length())
//         swap(s1, s2);

//     s2 = string(s1.length() - s2.length(), '0') + s2;
//     int n = s1.length();
//     int carry = 0;
//     string ans;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         int num = carry + (s1[i] - '0') + (s2[i] - '0');
//         ans = char(num % 10 + '0') + ans;
//         carry = num / 10;
//     }
//     if (carry != 0)
//         ans = char(carry % 10 + '0') + ans;
//     return ans;
// }

string removeChar(string str, int pos)
{
    str.erase(str.begin() + pos);
    return str;
}

bool eraseOneDigit(string firstnum, string secondnum, string thirdnum)
{
    int f = stoi(firstnum), s = stoi(secondnum), t = stoi(thirdnum);
    int n = firstnum.size();

    if (f + s == t)
        return true;
    else if (f + s < t)
        return false;
    else if (n > 1)
    {
        for (int i = 0; i < n; i++)
        {
            string newnum = removeChar(firstnum, i);
            if (newnum[0] != '0' && stoi(newnum) + s == t)
                return true;
        }
    }

    return false;
}

int main()
{
    int a = eraseOneDigit("167", "33", "100") ? 1 : 0;
    cout << a;
    return 0;
}