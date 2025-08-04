#pragma once

#include <stack>


class MyQueue
{
public:
    MyQueue()
    {
        
    }

    void push(int x)
    {
        m_Stack1.push(x);
    }

    int pop()
    {
        if (m_Stack2.empty())
        {
            while (!m_Stack1.empty())
            {
                m_Stack2.push(m_Stack1.top());
                m_Stack1.pop();
            }
        }
        int result = m_Stack2.top();
        m_Stack2.pop();
        return result;
    }

    int peek()
    {
        int result = pop();
        m_Stack2.push(result);
        return result;
    }

    bool empty()
    {
        return m_Stack1.empty() && m_Stack2.empty();
    }
private:
    std::stack<int> m_Stack1;
    std::stack<int> m_Stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
