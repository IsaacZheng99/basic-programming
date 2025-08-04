#pragma once

#include <vector>
#include <numeric>


class Solution134
{
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        int totalSum = 0;
        int curSum = 0;
        int result = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0)
            {
                curSum = 0;
                result = i + 1;
            }
        }

        if (totalSum < 0)
            return -1;

        return result;
    }
};


class Solution134
{
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        int curSum = 0;
        int minDiff = INT_MAX;
        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            if (curSum < minDiff)
                minDiff = curSum;
        }

        if (curSum < 0)
            return -1;

        if (minDiff >= 0)
            return 0;

        for (int i = gas.size() - 1; i >= 0; i--)
        {
            minDiff += gas[i] - cost[i];
            if (minDiff >= 0)
                return i;
        }

        return -1;
    }
};


class Solution134
{
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        if (std::accumulate(gas.begin(), gas.end(), 0) <
            std::accumulate(cost.begin(), cost.end(), 0))
            return -1;

        int size = gas.size();
        int minDiff = INT_MAX;
        int curDiff = 0;
        for (int i = 0; i < size * 2; i++)
        {
            if (curDiff > 0)
                curDiff = gas[i % size] - cost[i % size];
            else
                curDiff += gas[i % size] - cost[i % size];

            if (curDiff < minDiff)
                minDiff = curDiff;
        }

        int result = 0;
        int curLeft = 0;

        for (int i = 0; i < size * 2; i++)
        {
            if (curLeft + gas[i % size] - cost[i % size] > 0)
            {
                if (curLeft == 0)
                    result = i % size;
                curLeft += gas[i % size] - cost[i % size];
            }
            else
                curLeft = 0;

            if (curLeft >= -minDiff)
                return result;
        }

        return -1;

    }
};