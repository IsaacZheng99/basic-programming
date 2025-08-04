#pragma once

#include <queue>


class MyStack
{
public:
    MyStack()
    {

    }

    void push(int x)
    {
        m_Queue.push(x);
    }

    int pop()
    {
        int size = m_Queue.size();
        while (--size)
        {
            int front = m_Queue.front();
            m_Queue.pop();
            m_Queue.push(front);
        }

        int top = m_Queue.front();
        m_Queue.pop();
        return top;
    }

    int top()
    {
        int top = pop();
        m_Queue.push(top);
        return top;
    }

    bool empty()
    {
        return m_Queue.empty();

    }
private:
    std::queue<int> m_Queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */