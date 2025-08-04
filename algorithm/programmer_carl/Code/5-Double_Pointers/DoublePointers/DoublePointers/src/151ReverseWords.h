#pragma once

#include <string>


class Solution151
{
public:
    void deleteSpace(std::string& s)
    {
        int slow = 0;
        int fast = 0;
        while (fast < s.size())
        {
            if (s[fast] != ' ')
            {
                if (slow)
                    s[slow++] = ' ';

                while (fast < s.size() && s[fast] != ' ')
                    s[slow++] = s[fast++];
            }
            fast++;
        }
        s.resize(slow);
    }

    void reverseString(std::string& s, int start, int end)
    {
        for (int i = start, j = end; i < (start + end + 1) / 2; i++, j--)
            std::swap(s[i], s[j]);
    }
    
    std::string reverseWords(std::string s)
    {
        deleteSpace(s);
        reverseString(s, 0, s.size() - 1);
        int slow = 0;
        int fast = 0;
        while (fast <= s.size())
        {
            if (fast == s.size() || s[fast] == ' ')
            {
                reverseString(s, slow, fast - 1);
                slow = fast + 1;
            }
            fast++;
        }

        return s;
    }
};
