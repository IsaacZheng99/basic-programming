#pragma once

#include <vector>
#include <unordered_map>
#include <queue>


class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::vector<int> result;
        result.reserve(k);

        std::unordered_map<int, int> map;
        for (int num : nums)
            map[num]++;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, MyComparison> priorityQueue;

        for (std::unordered_map<int, int>::const_iterator it = map.begin(); it != map.end(); it++)
        {
            priorityQueue.push(*it);

            if (priorityQueue.size() > k)
                priorityQueue.pop();
        }

        while (!priorityQueue.empty())
        {
            result.push_back(priorityQueue.top().first);
            priorityQueue.pop();
        }

        return result;
    }
private:
    class MyComparison
    {
    public:
        bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
};