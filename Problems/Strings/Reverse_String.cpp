#include <bits/stdc++.h>
using namespace std;
// Remove Trailing Spaces
string revString(string A)
{
    string result = "";
    for (int i = A.length() - 1; i >= 0; i--)
    {
        if (A[i] != ' ')
        {
            int last = i;
            int first = i;
            while (i >= 0 && A[i] != ' ')
                --i;

            first = i + 1;

            result.append(A.begin() + first, A.begin() + last + 1);

            if (i > 0)
            {
                string str = A.substr(0, i + 1);
                string temp = "";
                temp.append(i + 1, ' ');
                if (str != temp)
                    result += ' ';
            }
        }
    }
    return result;
}

string revStringSimple(string A)
{
    string ans = "", w;
    stringstream ss(A);
    while (ss >> w)
        ans = " " + w + ans;
    return (ans.substr(1));
}

int main()
{
    string s = "   Hello My Name is Shubham          .              ";

    cout << revString(s) << endl;
    cout << revStringSimple(s);
    return 0;
}