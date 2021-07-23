#include <bits/stdc++.h>
using namespace std;

string nonRepeatingCharacter(string A)
{
    string res = "";
    queue<char> q;
    vector<int> charCount(26, 0);

    for (auto s : A)
    {
        q.push(s);
        charCount[s - 'a']++;

        while (!q.empty())
        {
            if (charCount[q.front() - 'a'] > 1)
                q.pop();
            else
            {
                res += q.front();
                break;
            }
        }

        if (q.empty())
            res += '#';
    }

    return res;
}

string nonRepeatingCharacter2(string A)
{
    unordered_map<char, int> mp;
    queue<char> q;
    string ans;

    for (auto c : A)
    {
        mp[c]++;
        q.push(c);
        while (!q.empty() && mp[q.front()] > 1)
            q.pop();

        if (!q.empty())
            ans.push_back(q.front());
        else
            ans.push_back('#');
    }

    return ans;
}

int main()
{

    return 0;
}