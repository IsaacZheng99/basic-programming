#pragma once

#include <vector>
#include <stack>
#include <algorithm>


class Solution42
{
public:
    int trap(std::vector<int>& height)
    {
        int result = 0;

        std::stack<int> stack;

        for (int i = 0; i < height.size(); i++)
        {

            while (!stack.empty() && height[stack.top()] < height[i])
            {
                int midHeight = height[stack.top()];
                stack.pop();
                if (!stack.empty())
                    result += (std::min(height[stack.top()], height[i]) - midHeight) * (i - stack.top() - 1);
            }

            stack.push(i);
        }

        return result;
    }
};


class Solution42
{
public:
    int trap(std::vector<int>& height)
    {
        int result = 0;

        std::stack<int> stack;

        for (int i = 0; i < height.size(); i++)
        {
            if (stack.empty())
                stack.push(i);
            else
            {
                if (height[stack.top()] > height[i])
                    stack.push(i);
                else if (height[stack.top()] == height[i])
                {
                    stack.pop();
                    stack.push(i);
                }
                else
                {
                    while (!stack.empty() && height[stack.top()] < height[i])
                    {
                        int midHeight = height[stack.top()];
                        stack.pop();
                        if (!stack.empty())
                            result += (std::min(height[stack.top()], height[i]) - midHeight) * (i - stack.top() - 1);
                    }

                    stack.push(i);
                }
            }
        }

        return result;
    }
};


class Solution42
{
public:
    int trap(std::vector<int>& height)
    {
        std::vector<int> leftMaxs(height.size(), 0);
        std::vector<int> rightMaxs(height.size(), 0);
        std::stack<int> leftStack;
        std::stack<int> rightStack;

        for (int i = 1; i < height.size(); i++)
        {
            while (!rightStack.empty() && height[rightStack.top()] < height[i])
                rightStack.pop();

            rightStack.push(i);
        }

        while (!rightStack.empty())
        {
            int curTopIndex = rightStack.top();
            rightStack.pop();
            if (!rightStack.empty())
            {
                for (int i = rightStack.top(); i < curTopIndex; i++)
                    rightMaxs[i] = height[curTopIndex];
            }
            else
                for (int i = 1; i < curTopIndex; i++)
                    rightMaxs[i] = height[curTopIndex];
        }

        for (int i = height.size() - 2; i >= 0; i--)
        {
            while (!leftStack.empty() && height[leftStack.top()] < height[i])
                leftStack.pop();

            leftStack.push(i);
        }
        while (!leftStack.empty())
        {
            int curTopIndex = leftStack.top();
            leftStack.pop();
            if (!leftStack.empty())
            {
                for (int i = curTopIndex + 1; i < height.size() - 1; i++)
                    leftMaxs[i] = height[curTopIndex];
            }
            else
                for (int i = curTopIndex + 1; i < height.size() - 1; i++)
                    leftMaxs[i] = height[curTopIndex];
        }

        int result = 0;
        for (int i = 1; i < height.size() - 1; i++)
        {
            int add = std::min(leftMaxs[i], rightMaxs[i]) - height[i];
            if (add > 0)
                result += add;
        }

        return result;
    }
};


class Solution42
{
public:
    int trap(std::vector<int>& height)
    {
        std::vector<int> leftMaxs(height.size(), 0);
        std::vector<int> rightMaxs(height.size(), 0);

        for (int i = 1; i < height.size() - 1; i++)
            leftMaxs[i] = std::max(leftMaxs[i - 1], height[i - 1]);

        for (int i = height.size() - 2; i > 0; i--)
            rightMaxs[i] = std::max(rightMaxs[i + 1], height[i + 1]);

        int result = 0;
        for (int i = 1; i < height.size() - 1; i++)
        {
            int add = std::min(leftMaxs[i], rightMaxs[i]) - height[i];
            if (add > 0)
                result += add;
        }

        return result;
    }
};


class Solution42
{
public:
    int trap(std::vector<int>& height)
    {
        int result = 0;

        for (int i = 0; i < height.size(); i++)
        {
            if (i == 0 || i == height.size() - 1)
                continue;

            int leftMaxHeight = INT_MIN;
            int rightMaxHeight = INT_MIN;
            for (int leftIndex = i - 1; leftIndex >= 0; leftIndex--)
            {
                if (height[leftIndex] > leftMaxHeight)
                    leftMaxHeight = height[leftIndex];
            }
            for (int rightIndex = i + 1; rightIndex < height.size(); rightIndex++)
            {
                if (height[rightIndex] > rightMaxHeight)
                    rightMaxHeight = height[rightIndex];
            }

            int add = std::min(leftMaxHeight, rightMaxHeight) - height[i];
            if (add > 0)
                result += add;
        }

        return result;
    }
};
