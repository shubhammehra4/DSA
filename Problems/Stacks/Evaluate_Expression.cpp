#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &A)
{
    stack<string> k;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == "/" || A[i] == "*" || A[i] == "+" || A[i] == "-")
        {
            int y = stoi(k.top());
            k.pop();
            int x = stoi(k.top());
            k.pop();
            switch (A[i][0])
            {
            case '+':
                k.push(to_string(x + y));
                break;
            case '-':
                k.push(to_string(x - y));
                break;
            case '*':
                k.push(to_string(x * y));
                break;
            case '/':
                k.push(to_string(x / y));
                break;
            }
        }
        else
            k.push(A[i]);
    }

    return stoi(k.top());
}

int main()
{

    return 0;
}