#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int> &nums)
{
    int moves = 0;
    int minElement = *min_element(begin(nums), end(nums));
    for (int element : nums)
        moves += element - minElement;

    return moves;
}

// same approach
int minMoves(vector<int> &nums)
{
    int n = nums.size();
    int minElement = *min_element(begin(nums), end(nums));
    int sum = accumulate(begin(nums), end(nums), 0);

    return sum - n * minElement;
}