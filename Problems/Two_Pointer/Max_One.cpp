#include <bits/stdc++.h>
using namespace std;

vector<int> maxone(vector<int> &A, int B)
{
    int l = 0, r = 0;
    int ansleft, ansright;
    int curr_len = 0;
    vector<int> res;

    while (r < A.size())
    {
        if (A[r] == 1)
        {
            if (curr_len < (r - l + 1))
            {
                ansleft = l;
                ansright = r;
                curr_len = r - l + 1;
            }
            r++;
        }
        else if (A[r] == 0 && B > 0)
        {
            B--;
            if (curr_len < (r - l + 1))
            {
                ansleft = l;
                ansright = r;
                curr_len = r - l + 1;
            }
            r++;
        }
        else
        {
            while (l < r && B == 0)
            {
                if (A[l] == 1)
                    l++;
                else
                {
                    B++;
                    l++;
                    break;
                }
            }
            if (l == r && B == 0)
            {
                l++;
                r++;
            }
        }
    }

    for (int i = ansleft; i <= ansright; i++)
        res.push_back(i);

    return res;
}

int main()
{
    vector<int> A = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1};
    int M = 2;
    vector<int> ans = maxone(A, M);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}