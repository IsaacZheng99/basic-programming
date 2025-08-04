#pragma once

#include <vector>


class Solution
{
public:
    void DFS(int start, int end, std::vector<std::vector<int>>& graph)
    {
        m_CurPath.push_back(start);

        if (start == end)
        {
            m_Result.push_back(m_CurPath);
            return;
        }

        for (int next : graph[start])
        {
            DFS(next, end, graph);
            m_CurPath.pop_back();
        }

        return;
    }

    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph)
    {
        DFS(0, graph.size() - 1, graph);
        
        return m_Result;
    }
private:
    std::vector<std::vector<int>> m_Result;
    std::vector<int> m_CurPath;
};