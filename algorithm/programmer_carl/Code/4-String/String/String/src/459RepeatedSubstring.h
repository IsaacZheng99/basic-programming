#pragma once

#include <string>


class Solution
{
public:
    bool repeatedSubstringPattern(std::string s)
    {
        std::string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        if (t.find(s) != std::string::npos)
            return true;
        return false;
    }
};

class Solution28
{
public:
    void getNext(const std::string& s, int* next)
    {
        int j = 0;
        next[0] = j;
        
        int i = 1;
        while (i < s.size())
        {
            if (s[i] == s[j])
            {
                j++;
                next[i++] = j;
            }
            else
            {
                if (j == 0)
                    next[i++] = 0;
                else
                    j = next[j - 1];
            }
        }
    }

    bool repeatedSubstringPattern(std::string s)
    {
        int* next = new int[s.size()];
        getNext(s, next);

        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0)
            {
                std::cout << i % 2 << std::endl;
                std::cout << next[i] << std::endl;
                std::cout << (i + 1) / 2 << std::endl;
                std::cout << (next[i] == (i + 1) / 2) << std::endl;
            }
            if (i % 2 && next[i] == (i + 1) / 2)
            {
                if (s.size() % next[i])
                    continue;
                else
                {
                    std::string candidate = s.substr(0, next[i]);
                    int cur = 0;
                    for (cur = 0; cur < s.size(); cur++)
                    {
                        if (candidate[cur % next[i]] != s[cur])
                            break;
                    }
                    if (cur == s.size())
                        return true;
                }
                    
            }
        }

        return false;
    }
};