#pragma once

#include <vector>


class Solution
{
public:
    bool IsValid(int row, int col, char num, std::vector<std::vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
            if (board[row][i] == num || board[i][col] == num)
                return false;

        int rowTimes = row / 3;
        int colTimes = col / 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[(row + i) % 3 + rowTimes * 3][(col + j) % 3 + colTimes * 3] == num)
                    return false;

        return true;
    }

    bool Backtracking(int row, int col, std::vector<std::vector<char>>& board)
    {
        if (row == 9)
            return true;

        int newRow = row;
        int newCol = col + 1;
        if (newCol == 9)
        {
            newRow = row + 1;
            newCol = 0;
        }

        if (board[row][col] != '.')
        {
            if (Backtracking(newRow, newCol, board))
                return true;
        }
        else
            for (char num = '1'; num <= '9'; num++)
            {
                if (!IsValid(row, col, num, board))
                    continue;
                board[row][col] = num;

                if (Backtracking(newRow, newCol, board))
                    return true;
                board[row][col] = '.';
            }
        return false;
    }

    void solveSudoku(std::vector<std::vector<char>>& board)
    {
        Backtracking(0, 0, board);
    }
};
