#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &img, int sr, int sc, int newColor)
{
    int m = img.size(), n = img[0].size();
    int oldColor = img[sr][sc];
    img[sr][sc] = newColor;

    if (newColor == oldColor)
        return img;

    queue<pair<int, int>> q;
    q.push({sr, sc});
    vector<int> dir = {-1, 0, 1, 0, -1};

    while (!q.empty())
    {
        int z = q.front().first, x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = z + dir[i], c = x + dir[i + 1];
            if (r >= 0 && r < m && c >= 0 && c < n && img[r][c] == oldColor)
            {
                img[r][c] = newColor;
                q.push({r, c});
            }
        }
    }

    return img;
}

// DFS

void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int m, int n, int color)
{
    if (sr < 0 || sr >= m || sc < 0 || sc >= n)
        return;
    else if (image[sr][sc] != color)
        return;

    image[sr][sc] = newColor;

    dfs(image, sr - 1, sc, newColor, m, n, color);
    dfs(image, sr + 1, sc, newColor, m, n, color);
    dfs(image, sr, sc - 1, newColor, m, n, color);
    dfs(image, sr, sc + 1, newColor, m, n, color);
}

vector<vector<int>> floodFill2(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    if (newColor == image[sr][sc])
        return image;

    int m = image.size();
    int n = image[0].size();
    int color = image[sr][sc];
    dfs(image, sr, sc, newColor, m, n, color);
    return image;
}

// 0, 0, 0
// 0, 1, 1
int main()
{
    return 0;
}