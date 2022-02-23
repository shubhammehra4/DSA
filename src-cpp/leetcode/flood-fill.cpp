#include <bits/stdc++.h>
using namespace std;

// bfs
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    const int color = image[sr][sc];

    if (newColor == color)
        return image;

    const int m = image.size();
    const int n = image[0].size();

    queue<pair<int, int>> q;
    q.push({sr, sc});

    vector<int> directions{-1, 0, 1, 0, -1};

    while (!q.empty())
    {
        auto pixel = q.front();
        q.pop();
        image[pixel.first][pixel.second] = newColor;

        for (int i = 0; i < 4; i++)
        {
            auto r = pixel.first + directions[i];
            auto c = pixel.second + directions[i + 1];

            if (r >= 0 && r < m && c >= 0 && c < n && image[r][c] == color)
                q.push({r, c});
        }
    }

    return image;
}

// dfs
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    const int color = image[sr][sc];
    if (newColor == color)
        return image;

    const int m = image.size();
    const int n = image[0].size();

    function<void(int, int)> dfsUtil = [&image, &m, &n, &color, &newColor, &dfsUtil](int r, int c)
    {
        if (image[r][c] == color)
        {
            image[r][c] = newColor;
            if (r >= 1)
                dfsUtil(r - 1, c);
            if (c >= 1)
                dfsUtil(r, c - 1);
            if (r + 1 < m)
                dfsUtil(r + 1, c);
            if (c + 1 < n)
                dfsUtil(r, c + 1);
        }
    };

    dfsUtil(sr, sc);

    return image;
}