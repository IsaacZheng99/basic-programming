#pragma once

#include <vector>
#include <stack>


class Solution739
{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        std::vector<int> result(temperatures.size(), 0);

        std::stack<int> stack;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()])
            {
                int curTopIndex = stack.top();
                stack.pop();
                result[curTopIndex] = i - curTopIndex;
            }
            stack.push(i);
        }

        return result;
    }
};