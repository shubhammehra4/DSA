#include <bits/stdc++.h>
using namespace std;

void findPermutations(string s, int l, int r, vector<string> &res)
{
    if (l == r)
    {
        // cout << s << endl;
        res.push_back(s);
        return;
    }

    for (int i = l; i <= r; i++)
    {
        swap(s[i], s[l]);
        findPermutations(s, l + 1, r, res);
        swap(s[l], s[i]);
    }
}

vector<string> permutationString(string s)
{
    int n = s.size();
    vector<string> res;

    findPermutations(s, 0, n - 1, res);

    return res;
}

int main()
{
    permutationString("avdc");
    return 0;
}