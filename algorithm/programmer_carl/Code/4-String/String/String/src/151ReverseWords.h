#pragma once

#include <string>


class Solution151
{
public:
    std::string reverseWords(std::string s)
    {
        deleteSpace(s);
        reverse(s, 0, s.size() - 1);

        int fast = 0;
        int slow = 0;
        while (fast < s.size())
        {
            if (s[slow] == ' ')
                slow++;
            if (s[fast] == ' ' || fast != s.size() - 1 && s[fast] != ' ' && s[fast + 1] != ' ')
                fast++;
            else
            {
                reverse(s, slow, fast);
                fast++;
                slow = fast;
            }
        }


        return s;
    }

    void reverse(std::string& s, int begin, int end)
    {
        while (begin < end)
        {
            std::swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }

    void deleteSpace(std::string& s)
    {
        int slow = 0;
        int fast = 0;

        while (fast < s.size())
        {
            if (slow == 0 && s[fast] == ' '
                || fast != s.size() - 1 && s[fast] == ' ' && s[fast + 1] == ' '
                || fast == s.size() - 1 && s[fast] == ' ')
                fast++;
            else
            {
                s[slow] = s[fast];
                slow++;
                fast++;
            }
        }
        s.resize(slow);
    }

    void deleteSpace2(std::string& s)
    {
        int cur = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                if (cur)
                    s[cur++] = ' ';
                while (i < s.size() && s[i] != ' ')
                    s[cur++] = s[i++];
            }
        }
        s.resize(cur);
    }
};