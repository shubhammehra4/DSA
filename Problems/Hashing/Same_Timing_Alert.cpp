#include <bits/stdc++.h>
using namespace std;

bool timeDiff(vector<string> t, int i)
{
    int j = i + 2;
    int time1 = ((t[i][0] - '0') * 10 + (t[i][1] - '0')) * 60 + ((t[i][3] - '0') * 10 + (t[i][4] - '0'));
    int time2 = ((t[j][0] - '0') * 10 + (t[j][1] - '0')) * 60 + ((t[j][3] - '0') * 10 + (t[j][4] - '0'));

    if (abs(time2 - time1) <= 60)
        return true;
    return false;
}

vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
{
    unordered_map<string, vector<string>> m;
    vector<string> ans;

    for (int i = 0; i < keyName.size(); i++)
        m[keyName[i]].push_back(keyTime[i]);

    for (auto i : m)
    {
        sort(i.second.begin(), i.second.end());
        for (int j = 0; j + 2 < i.second.size(); j++)
        {
            if (timeDiff(i.second, j))
            {
                ans.push_back(i.first);
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// Alternative

vector<string> alertNames2(vector<string> &names, vector<string> &times)
{
    unordered_map<string, vector<int>> log;
    vector<string> res;
    for (int i = 0; i < names.size(); ++i)
        log[names[i]].push_back(stoi(times[i].substr(0, 2)) * 60 + stoi(times[i].substr(3)));
    for (auto &p : log)
    {
        sort(begin(p.second), end(p.second));
        for (int i = 0, j = 0; i < p.second.size(); ++i)
        {
            while (p.second[i] - p.second[j] > 60)
                ++j;
            if (i - j >= 2)
            {
                res.push_back(p.first);
                break;
            }
        }
    }
    sort(begin(res), end(res));
    return res;
}

int main()
{
    return 0;
}