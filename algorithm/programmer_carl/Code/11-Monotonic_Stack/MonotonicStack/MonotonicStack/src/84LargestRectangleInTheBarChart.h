#pragma once

#include <vector>
#include <stack>
#include <algorithm>


class Solution84
{
public:
    int largestRectangleArea(std::vector<int>& heights)
    {
        int result = 0;

        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        std::stack<int> stack;

        for (int i = 0; i < heights.size(); i++)
        {
            while (!stack.empty() && heights[stack.top()] > heights[i])
            {
                int midHeight = heights[stack.top()];
                stack.pop();

                if (!stack.empty())
                    result = std::max(result, midHeight * (i - stack.top() - 1));
            }

            stack.push(i);
        }

        return result;
    }
};


class Solution84
{
public:
    int largestRectangleArea(std::vector<int>& heights)
    {
        int result = 0;

        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        std::stack<int> stack;
        stack.push(0);

        for (int i = 1; i < heights.size(); i++)
        {
            if (heights[stack.top()] < heights[i])
                stack.push(i);
            else if (heights[i] == heights[stack.top()])
            {
                stack.pop();
                stack.push(i);
            }
            else
            {
                while (!stack.empty() && heights[stack.top()] > heights[i])
                {
                    int midIndex = stack.top();
                    stack.pop();

                    if (!stack.empty())
                        result = std::max(result, heights[midIndex] * (i - stack.top() - 1));
                }

                stack.push(i);
            }
        }

        return result;
    }
};


class Solution84
{
public:
    int largestRectangleArea(std::vector<int>& heights)
    {
        std::vector<int> leftLessIndex(heights.size());
        std::vector<int> rightLessIndex(heights.size());
        leftLessIndex[0] = -1;
        rightLessIndex[heights.size() - 1] = heights.size();

        for (int i = 1; i < heights.size(); i++)
        {
            int lessIndex = i - 1;
            
            while (lessIndex > 0 && heights[i] <= heights[lessIndex])
                lessIndex = leftLessIndex[lessIndex];

            leftLessIndex[i] = lessIndex;
        }


        for (int i = heights.size() - 2; i >= 0; i--)
        {
            int lessIndex = i + 1;

            while (lessIndex < heights.size() - 2 && heights[i] <= heights[lessIndex])
                lessIndex = rightLessIndex[lessIndex];

            rightLessIndex[i] = lessIndex;
        }

        int result = 0;
        for (int i = 0; i < heights.size(); i++)
            result = std::max(result, heights[i] * (rightLessIndex[i] - leftLessIndex[i] - 1));

        return result;
    }
};


class Solution84
{
public:
    int largestRectangleArea(std::vector<int>& heights)
    {
        int result = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            int leftIndex = i;
            int rightIndex = i;
            while (leftIndex >= 0 && heights[leftIndex] >= heights[i])
                leftIndex--;
            while (rightIndex <= heights.size() - 1 && heights[rightIndex] >= heights[i])
                rightIndex++;

            result = std::max(result, heights[i] * (rightIndex - leftIndex - 1));
        }

        return result;
    }
};