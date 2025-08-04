#pragma once

#include <string>
#include <stack>


class Solution1047
{
public:
    std::string removeDuplicates(std::string s)
    {
        std::string result;

        for (char c : s)
        {
            if (result.empty() || !result.empty() && result.back() != c)
                result.push_back(c);
            else
                result.pop_back();
        }

        return result;
    }
};


//class Solution1047
//{
//public:
//    std::string removeDuplicates(std::string s) 
//    {
//        std::stack<char> stack;
//
//        for (char c : s)
//        {
//            if (stack.empty() || !stack.empty() && stack.top() != c)
//                stack.push(c);
//            else
//                stack.pop();
//        }
//
//        std::string result;
//        while (!stack.empty())
//        {
//            result = stack.top() + result;
//            stack.pop();
//        }
//
//        return result;
//    }
//};
