#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s)
{
    vector<int> cnt(26, 0);
    for (auto c : s)
        cnt[c - 'a']++;

    bitset<26> visited;
    string res = "";

    for (auto c : s)
    {
        auto i = c - 'a';
        cnt[i]--;

        if (visited.test(i) == 0)
        {
            while (!res.empty() && res.back() > c && cnt[res.back() - 'a'] > 0)
            {
                visited.set(res.back() - 'a', false);
                res.pop_back();
            }

            res += c;
            visited.set(i, true);
        }
    }

    return res;
}

// stack
string removeDuplicateLetters(string s)
{
    int n = s.size();
    vector<int> lastIndex(26, 0);
    for (int i = 0; i < n; i++)
        lastIndex[s[i] - 'a'] = i;

    stack<char> st;
    bitset<26> visited;

    for (int i = 0; i < n; i++)
    {
        auto c = s[i];

        if (visited.test(c - 'a') == 0)
        {
            while (!st.empty() && st.top() > c && lastIndex[st.top() - 'a'] > i)
            {
                visited.set(st.top() - 'a', false);
                st.pop();
            }

            st.push(c);
            visited.set(c - 'a', true);
        }
    }

    string res = "";
    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }

    return res;
}
