#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

class Solution242
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        int counts[26] = {0};
        for (int i = 0; i < s.size(); i++)
            counts[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++)
            counts[t[i] - 'a']--;
        for (int i = 0; i < 26; i++)
            if (counts[i] != 0)
                return false;
        return true;
    }
};


//class Solution242
//{
//public:
//    bool isAnagram(std::string s, std::string t)
//    {
//        std::unordered_map<char, int> sMap;
//        std::unordered_map<char, int> tMap;
//
//        for (char c : s)
//            sMap[c]++;
//        for (char c : t)
//            tMap[c]++;
//
//        if (sMap.size() != tMap.size())
//            return false;
//
//        for (auto& [c, num] : sMap)
//        {
//            auto it = tMap.find(c);
//            if (it == tMap.end())
//                return false;
//            else if (it->second != num)
//                return false;
//        }
//
//        return true;
//    }
//};