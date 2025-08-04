#pragma once

#include <vector>
#include <deque>


class MonotonousQueue
{
public:
    void Push(int value)
    {
        while (!m_Deque.empty() && m_Deque.back() < value)
                m_Deque.pop_back();

        m_Deque.push_back(value);
    }

    void Pop(int value)
    {
        if (!m_Deque.empty() && value == m_Deque.front())
            m_Deque.pop_front();
    }

    int Front()
    {
        return m_Deque.front();
    }

private:
    std::deque<int> m_Deque;
};

class Solution239
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        std::vector<int> result;
        result.reserve(nums.size() - k + 1);
        MonotonousQueue monotonousQueue;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i < k)
            {
                monotonousQueue.Push(nums[i]);

                if (i == k - 1)
                    result.push_back(monotonousQueue.Front());
            }
            else
            {
                monotonousQueue.Pop(nums[i - k]);
                monotonousQueue.Push(nums[i]);
                result.push_back(monotonousQueue.Front());
            }
        }

        return result;
    }
};