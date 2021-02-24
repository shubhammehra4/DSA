#include <bits/stdc++.h>
using namespace std;
#define n 7

void printSolution (int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
                cout << "Q ";
            else
                cout << "- ";
        }

        cout << "\n";
    }
}

bool BoundCheck (int board[n][n], int row, int col) //Checking only rows and diagonals as columns are set to be unique
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQBacktracing (int board[n][n], int col)
{
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (BoundCheck (board, i, col) )
        {
            board[i][col] = 1;

            if (solveNQBacktracing (board, col + 1) ) //Recursion
                return true;

            board[i][col] = 0; //Bounds are not satisfied
        }
    }

    return false;
}

void NQueens ()
{
    int board[n][n] = {0};

    if (solveNQBacktracing (board, 0) == false)
        printf ("Solution does not exist");
    else
        printSolution (board);
}

int main()
{
    NQueens ();// This function only prints one of the possible solutions and not all of them
    return 0;
}