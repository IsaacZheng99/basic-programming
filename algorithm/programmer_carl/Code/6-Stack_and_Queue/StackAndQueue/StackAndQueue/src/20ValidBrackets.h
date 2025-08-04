#pragma once

#include <string>
#include <stack>


class Solution20
{
public:
    bool isValid(std::string s)
    {
        std::stack<int> stack;
        for (char c : s)
        {
            if (c == ')')
            {
                if (!stack.empty() && stack.top() == '(')
                    stack.pop();
                else
                    return false;
            }
            else if (c == ']')
            {
                if (!stack.empty() && stack.top() == '[')
                    stack.pop();
                else
                    return false;
            }
            else if (c == '}')
            {
                if (!stack.empty() && stack.top() == '{')
                    stack.pop();
                else
                    return false;
            }
            else
                stack.push(c);
        }

        if (!stack.empty())
            return false;
        return true;
    }
};