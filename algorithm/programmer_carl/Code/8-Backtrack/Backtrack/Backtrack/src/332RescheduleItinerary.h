#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>


class Solution
{
public:
    std::unordered_map<std::string, std::vector<bool>> GetUsedMap(std::unordered_map<std::string, std::vector<std::string>>& ticketsMap)
    {
        std::unordered_map<std::string, std::vector<bool>> usedMap;

        for (auto& [start, ends] : ticketsMap)
        {
            std::vector<bool> usedVector(ends.size(), false);
            usedMap[start] = usedVector;
        }
        
        return usedMap;
    }

    std::unordered_map<std::string, std::vector<std::string>> GetTicketsMap(std::vector<std::vector<std::string>>& tickets)
    {
        std::unordered_map<std::string, std::vector<std::string>> ticketsMap;
        for (auto ticket : tickets)
            ticketsMap[ticket[0]].push_back(ticket[1]);

        for (auto& [start, ends] : ticketsMap)
            std::sort(ends.begin(), ends.end());

        return ticketsMap;
    }

    bool Backtracking(
        std::string start, 
        int ticketsNum, 
        std::unordered_map<std::string, std::vector<std::string>> ticketsMap, 
        std::unordered_map<std::string, std::vector<bool>> usedMap)
    {
        if (m_CurStations.size() == ticketsNum + 1)
            return true;

        for (int i = 0; i < ticketsMap[start].size(); i++)
        {
            if (usedMap[start][i])
                continue;

            std::string nextStation = ticketsMap[start][i];
            std::cout << nextStation 
            m_CurStations.push_back(nextStation);
            usedMap[start][i] = true;
            if (Backtracking(nextStation, ticketsNum, ticketsMap, usedMap))
                return true;
            m_CurStations.pop_back();
            usedMap[start][i] = false;
        }

        return false;
    }

    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets)
    {
        std::unordered_map<std::string, std::vector<std::string>> ticketsMap = GetTicketsMap(tickets);
        std::unordered_map<std::string, std::vector<bool>> usedMap = GetUsedMap(ticketsMap);

        int ticketsNum = tickets.size();
        m_CurStations.reserve(ticketsNum + 1);
        m_CurStations.push_back("JFK");
        Backtracking("JFK", ticketsNum, ticketsMap, usedMap);
        return m_CurStations;
    }
private:
    std::vector<std::string> m_CurStations;
};
