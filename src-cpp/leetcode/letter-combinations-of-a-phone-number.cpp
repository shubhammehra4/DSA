#include <bits/stdc++.h>
using namespace std;

const vector<string> telepad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// iterative
// building on top of prev result
vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};

    vector<string> res;

    for (auto digit : digits)
    {
        vector<string> nextRes;
        for (auto candidate : telepad[digit - '2'])
        {
            // build next combinations using prev result
            for (auto str : res)
                nextRes.push_back(str + candidate);
        }

        swap(res, nextRes);
    }

    return res;
}

// recursive
vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};

    vector<string> res;
    const vector<string> telepad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    function<void(string &, int, string)> helper =
        [&res, &helper, &telepad](string &digits, int i, string combi)
    {
        if (i == size(digits))
        {
            res.push_back(move(combi));
            return;
        }

        for (auto candidate : telepad[digits[i] - '2'])
            helper(digits, i + 1, combi + candidate);
    };

    helper(digits, 0, "");
    return res;
}
