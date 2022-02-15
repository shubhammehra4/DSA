#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};
auto compareX = [](Point a, Point b) -> bool
{ a.x < b.x; };

auto compareY = [](Point a, Point b) -> bool
{ a.y < b.y; };

float getDistance(Point a, Point b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

pair<pair<Point, Point>, float> closestPairBF(vector<Point> &grid)
{
    int n = grid.size();
    float minDistance = FLT_MAX;
    pair<Point, Point> closestPoints;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            float distance = getDistance(grid[i], grid[j]);
            if (distance < minDistance)
            {
                closestPoints = {grid[i], grid[j]};
                minDistance = distance;
            }
        }
    }

    return make_pair(closestPoints, minDistance);
}

pair<pair<Point, Point>, float> stripClosest(vector<Point> &strip, pair<pair<Point, Point>, float> &minRes)
{
    int n = strip.size();
    pair<Point, Point> closestPoints = minRes.first;
    float minDist = minRes.second;

    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < minDist; ++j)
        {
            float distance = getDistance(strip[i], strip[j]);
            if (distance < minDist)
            {
                minDist = distance;
                closestPoints = make_pair(strip[i], strip[j]);
            }
        }
    }

    return make_pair(closestPoints, minDist);
}

pair<pair<Point, Point>, float> closestPairUtil(vector<Point> &grid, int start, int end)
{
    if (end - start <= 3)
        return closestPairBF(grid);

    int mid = (end - start) / 2;
    auto midPont = grid[mid];
    auto leftGridRes = closestPairUtil(grid, start, mid);
    auto rightRightRes = closestPairUtil(grid, mid + 1, end);

    pair<pair<Point, Point>, float> res = leftGridRes.second < rightRightRes.second ? leftGridRes : rightRightRes;
    auto distance = res.second;

    vector<Point> strip;
    for (auto point : grid)
    {
        if (abs(point.x - midPont.x) < distance)
            strip.push_back(point);
    }

    return stripClosest(strip, res);
}

auto closestPair(vector<Point> grid)
{
    sort(begin(grid), end(grid), compareX);
    int n = grid.size();
    return closestPairUtil(grid, 0, n);
}

int main()
{
    vector<Point> P = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};

    auto ans = closestPair(P);

    cout << "The smallest distance is " << ans.second << endl;

    cout << "Points are \n"
         << ans.first.first.x << "," << ans.first.first.y << endl
         << ans.first.second.x << "," << ans.first.second.y;
    return 0;
}