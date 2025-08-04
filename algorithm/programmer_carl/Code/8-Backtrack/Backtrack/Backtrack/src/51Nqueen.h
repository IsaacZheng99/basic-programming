#pragma once

#include <vector>
#include <string>
#include <algorithm>


class Solution
{
public:
    bool IsValidPlace(int row, int col, int n, std::vector<std::string>& curBoard)
    {
        for (int i = 0; i < n; i++)
        {
            if (curBoard[i][col] == 'Q')
                return false;

        }


        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (curBoard[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (curBoard[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void Backtracking(int row, int n, std::vector<std::string>& curBoard)
    {
        if (row == n)
        {
            m_Result.push_back(curBoard);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (!IsValidPlace(row, col, n, curBoard))
                continue;
            curBoard[row][col] = 'Q';
            Backtracking(row + 1, n, curBoard);
            curBoard[row][col] = '.';
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::string> curBoard(n, std::string(n, '.'));
        Backtracking(0, n, curBoard);
        return m_Result;
    }
public:
    std::vector<std::vector<std::string>> m_Result;
};