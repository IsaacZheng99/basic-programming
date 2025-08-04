#pragma once

#include <string>


class Solution28
{
public:
    void getNext(const std::string& needle, int* next)
    {
        int j = 0;
        next[0] = j;

        int i = 1;
        while (i < needle.size())
        {
            if (needle[i] == needle[j])
            {
                j++;
                next[i++] = j;
            }
            else
            {
                if (j == 0)
                {
                    next[i++] = 0;
                }
                else
                {
                    j = next[j - 1];
                }
            }
        }
    }

    int strStr(std::string haystack, std::string needle)
    {
        int* next = new int[needle.size()];
        getNext(needle, next);

        int i = 0;
        int j = 0;

        while (i < haystack.size())
        {
            if (haystack[i] == needle[j])
            {
                if (j == needle.size() - 1)
                    return i - needle.size() + 1;
                else
                {
                    i++;
                    j++;
                }
            }
            else
            {
                if (j == 0)
                    i++;
                else
                    j = next[j - 1];
            }
        }

        return -1;
    }
};


//class Solution28
//{
//public:
//    void getNext(const std::string& needle, int* next)
//    {
//        int j = 0;
//        next[0] = j;
//        
//        int i = 1;
//        while (i < needle.size())
//        {
//            if (needle[i] == needle[j])
//            {
//                j++;
//                next[i++] = j;
//            }
//            else
//            {
//                if (j == 0)
//                {
//                    next[i++] = 0;
//                }
//                else
//                {
//                    j = next[j - 1];
//                }
//            }
//        }
//
//        /*int j = 0;
//        next[0] = j;
//
//        for (int i = 1; i < needle.size(); i++)
//        {
//            while (j > 0 && needle[i] != needle[j])
//            {
//                j = needle[j - 1];
//            }
//
//            if (needle[i] == needle[j])
//            {
//                j++;
//            }
//
//            next[i] = j;
//        }*/
//    }
//
//    int strStr(std::string haystack, std::string needle)
//    {
//        int* next = new int[needle.size()];
//        getNext(needle, next);
//
//        int curBegin = 0;
//        int i = 0;
//        int j = 0;
//
//        while (i < haystack.size())
//        {
//            if (haystack[i] == needle[j])
//            {
//                if (j == needle.size() - 1)
//                    return curBegin;
//                else
//                    i++;
//                    j++;
//            }
//            else
//            {
//                if (j == 0)
//                    i++;
//                else
//                    j = next[j - 1];
//                curBegin = i - j;
//            }
//        }
//
//        return -1;
//    }
//};


//class Solution28
//{
//public:
//    int strStr(std::string haystack, std::string needle)
//    {
//        for (int i = 0; i < haystack.size(); i++)
//        {
//            int cur1 = i;
//            int cur2 = 0;
//            while (cur1 < haystack.size() && cur2 < needle.size())
//            {
//                if (haystack[cur1] != needle[cur2])
//                    break;
//                cur1++;
//                cur2++;
//            }
//            if (cur2 == needle.size())
//                return i;
//        }
//
//        return -1;
//    }
//};