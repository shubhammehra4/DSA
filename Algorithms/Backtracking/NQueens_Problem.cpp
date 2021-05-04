#include <bits/stdc++.h>
using namespace std;

class NQueens
{
    int N;
    vector<vector<int>> board;
    vector<int> ld;
    vector<int> rd;
    vector<int> cl;

public:
    NQueens(int N);
    void solve();
    bool solveUtil(int col);
    bool Boundcheck(int row, int col);
    void printBoard();
};

NQueens::NQueens(int N)
{
    this->N = N;
    board.resize(N, vector<int>(N, 0));
    ld.resize(2 * N + 1, 0);
    rd.resize(2 * N + 1, 0);
    cl.resize(2 * N + 1, 0);
}

void NQueens::printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
                cout << "Q ";
            else
                cout << "- ";
        }

        cout << "\n";
    }
}
// Naive
bool NQueens::Boundcheck(int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool NQueens::solveUtil(int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1) && cl[i] != 1)
        {
            board[i][col] = 1;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

            if (solveUtil(col + 1))
                return true;

            board[i][col] = 0; // BACKTRACK
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
        }
        // if (Boundcheck(i, col))
        // {
        //     board[i][col] = 1;

        //     if (solveUtil(col + 1)) //Recursion
        //         return true;

        //     board[i][col] = 0; //Bounds are not satisfied
        // }
    }

    return false;
}

void NQueens::solve()
{
    if (solveUtil(0) == false)
        printf("Solution does not exist");
    else
        printBoard();
}

int main()
{
    NQueens s(10);
    s.solve();
    return 0;
}