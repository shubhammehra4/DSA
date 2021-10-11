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
// O(n^2)
float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (distance(P[i], P[j]) < min)
                min = distance(P[i], P[j]);

    return min;
}

float stripClosest(vector<Point> strip, float d)
{
    float min = d;
    int n = strip.size();
    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < min; ++j)
            if (distance(strip[i], strip[j]) < min)
                min = distance(strip[i], strip[j]);

    return min;
}

float closestPairUtil(Point P[], int n)
{
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n / 2;
    Point midPoint = P[mid];
    float dLeft = closestPairUtil(P, mid);
    float dRight = closestPairUtil(P + mid, n - mid);
    float d = min(dLeft, dRight);
    vector<Point> strip;

    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip.push_back(P[i]);

    return min(d, stripClosest(strip, d));
}

// O(nlogn)
float closestPair(Point P[], int n)
{
    sort(P, P + n, compareX);
    return closestPairUtil(P, n);
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closestPair(P, n);
    return 0;
}