#include <bits/stdc++.h>
using namespace std;

vector<string> removeComments(vector<string> &src)
{
    int n = src.size(), m;
    vector<string> ans;
    string s;
    bool comment = false;
    for (int i = 0; i < n; i++)
    {
        m = src[i].size();
        for (int j = 0; j < m; j++)
        {
            if (!comment && j + 1 < m && src[i][j] == '/' && src[i][j + 1] == '/')
                break;
            else if (!comment && j + 1 < m && src[i][j] == '/' && src[i][j + 1] == '*')
                comment = true, j++;
            else if (comment && j + 1 < m && src[i][j] == '*' && src[i][j + 1] == '/')
                comment = false, j++;
            else if (!comment)
                s.push_back(src[i][j]);
        }

        if (!comment && s.size())
        {
            ans.push_back(s);
            s.clear();
        }
    }

    return ans;
}

int main()
{

    return 0;
}