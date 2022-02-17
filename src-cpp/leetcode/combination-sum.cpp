#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> combination;

void combinationSum(vector<int> &candidates, int target, int begin)
{
    if (target == 0)
    {
        res.push_back(combination);
        return;
    }

    for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i)
    {
        combination.push_back(candidates[i]);

        combinationSum(candidates, target - candidates[i], i);

        combination.pop_back();
    }
}

vector<vector<int>> combinationSum(std::vector<int> &candidates, int target)
{
    vector<int> filteredCopy; // Not neccessary
    copy_if(begin(candidates), end(candidates), back_inserter(filteredCopy), [&target](auto &elem)
            { return elem <= target; });
    sort(begin(filteredCopy), end(filteredCopy));

    combinationSum(filteredCopy, target, 0);

    return res;
}
