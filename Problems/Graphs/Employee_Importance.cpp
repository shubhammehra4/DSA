#include <bits/stdc++.h>
using namespace std;

// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

int getImportance(vector<Employee *> employees, int id)
{
    int total = 0;
    queue<int> ids;
    ids.push(id);
    while (!ids.empty())
    {
        for (int j = 0; j < employees.size(); j++)
        {
            if (employees[j]->id == ids.front())
            {
                ids.pop();
                total += employees[j]->importance;

                for (auto j : employees[j]->subordinates)
                    ids.push(j);
            }
        }
    }
    return total;
}

int main()
{

    return 0;
}