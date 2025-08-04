#pragma once

#include <vector>
#include <string>
#include <stack>


class Solution150
{
public:
    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<int> stack;

        for (std::string token : tokens)
        {
            if (token != "+" && token != "-" && token != "*" && token != "/")
                stack.push(std::stoi(token));
            else
            {
                int num2 = stack.top();
                stack.pop();
                int num1 = stack.top();
                stack.pop();

                if (token == "+")
                    stack.push(num1 + num2);
                else if (token == "-")
                    stack.push(num1 - num2);
                else if (token == "*")
                    stack.push(num1 * num2);
                else if (token == "/")
                    stack.push(num1 / num2);
            }
        }

        return stack.top();
    }
};