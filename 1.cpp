/*
    We are given an array of n points in the plane, and the problem is to 
    find out the closest pair of points in the array.
*/
#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;
};

bool compareX(Point a, Point b) { return a.x < b.x; }

bool compareY(Point a, Point b) { return a.y < b.y; }

float distance(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

float bruteForce(Point P[], int n)
{
    float closestDistance = INT_MAX;
    pair<int, int> points;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float temp = distance(P[i], P[j]);
            if (temp < closestDistance)
            {
                closestDistance = temp;
                points = {i, j};
            }
        }
    }

    cout << points.first << " " << points.second << endl;

    return closestDistance;
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << bruteForce(P, n);
    return 0;
}