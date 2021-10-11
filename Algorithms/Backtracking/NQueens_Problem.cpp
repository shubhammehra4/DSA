#include <bits/stdc++.h>
using namespace std;

/*
Optimization:
    The sum of i and j is constant and unique for each right diagonal where i is the row of element and j is the
    column of element.

    The difference of i and j is constant and unique for each left diagonal where i and j are row and column of element respectively.
*/

class NQueens
{
    int N;
    vector<vector<int>> board;
    /* ld is an array where its indices indicate row-col+N-1
    (N-1) is for shifting the difference to store negative 
    indices */
    vector<int> ld;
    /* rd is an array where its indices indicate row+col
    and used to check whether a queen can be placed on 
    right diagonal or not*/
    vector<int> rd;
    /*column array where its indices indicates column and 
    used to check whether a queen can be placed in that
    row or not*/
    vector<int> cl;

public:
    NQueens(int N);
    bool Boundcheck(int row, int col);
    bool solveUtil(int col);
    void solve();
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
        // Naive Method
        // if (Boundcheck(i, col))
        // {
        //     board[i][col] = 1;

        //     if (solveUtil(col + 1)) //Recursion
        //         return true;

        //     board[i][col] = 0; //Bounds are not satisfied
        // }

        if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1) && cl[i] != 1)
        {
            board[i][col] = 1;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

            if (solveUtil(col + 1))
                return true;

            board[i][col] = 0; // BACKTRACK
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
        }
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

int main()
{
    NQueens q(11);
    q.solve();
    return 0;
}