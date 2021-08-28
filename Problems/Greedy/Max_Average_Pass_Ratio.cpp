#include <bits/stdc++.h>
using namespace std;

/*
    Calculate the profit each class will have if we add one student 
    and store it in a max heap
    Then for all extra students take the most profitable and add it to the total
*/

// Profit of adding one student
double profit(double pass, double total)
{
    return (pass + 1) / (total + 1) - pass / total;
};

double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    double total = 0;
    priority_queue<pair<double, array<int, 2>>> pq;

    for (auto &c : classes)
    {
        total += (double)c[0] / c[1];
        pq.push({profit(c[0], c[1]), {c[0], c[1]}});
    }
    while (extraStudents--)
    {
        auto [added_profit, c] = pq.top();
        pq.pop();
        total += added_profit;
        pq.push({profit(c[0] + 1, c[1] + 1), {c[0] + 1, c[1] + 1}});
    }

    return total / classes.size();
}

int main()
{

    return 0;
}