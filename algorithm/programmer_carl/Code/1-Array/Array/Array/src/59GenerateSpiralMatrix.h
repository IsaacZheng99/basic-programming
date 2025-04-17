#pragma once
#include <vector>

class Solution59
{
public:
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        int current = 1;
        std::vector<std::vector<int>> result;
        result.reserve(n);
        for (int i = 0; i < n; i++)
            result.push_back(std::vector<int>(n));
        int loop = 0;

        while (loop < (n + 1) / 2) 
        {
            for (int col = loop; col < n - loop - 1; col++)
            {
                result[loop][col] = current;
                current++;
            }

            for (int row = loop; row < n - loop - 1; row++)
            {
                result[row][n - loop - 1] = current;
                current++;
            }

            for (int col = n - loop - 1; col > loop; col--)
            {
                result[n - loop - 1][col] = current;
                current++;
            }

            for (int row = n - loop - 1; row > loop; row--)
            {
                result[row][loop] = current;
                current++;
            }
            loop++;
        }


        if (n % 2 == 1)
            result[n / 2][n / 2] = current;
        return result;
    }
};