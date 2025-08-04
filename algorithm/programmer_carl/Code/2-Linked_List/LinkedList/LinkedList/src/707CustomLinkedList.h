#pragma once

class MyLinkedList {
public:
    struct Node
    {
        Node()
            : Val(0), Next(nullptr) {}

        Node(int val)
            : Val(val), Next(nullptr) {}

        Node(int val, Node* next)
            : Val(val), Next(next) {}

        int Val;
        Node* Next;
    };

    MyLinkedList()
        : m_DummyHead(new Node()), m_Length(0) {}

    int get(int index)
    {
        if (index < 0 || index > m_Length - 1)
            return -1;
        Node* cur = m_DummyHead->Next;
        while (index--)
            cur = cur->Next;
        return cur->Val;
    }

    void addAtHead(int val)
    {
        Node* curHead = m_DummyHead->Next;
        Node* newHead = new Node(val, curHead);
        m_DummyHead->Next = newHead;
        m_Length++;
    }

    void addAtTail(int val)
    {
        Node* cur = m_DummyHead;
        while (cur->Next)
            cur = cur->Next;
        cur->Next = new Node(val);
        m_Length++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > m_Length)
            return;

        Node* cur = m_DummyHead;
        while (index--)
            cur = cur->Next;
        Node* curNext = cur->Next;
        cur->Next = new Node(val, curNext);
        m_Length++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > m_Length - 1)
            return;

        Node* cur = m_DummyHead;
        while (index--)
            cur = cur->Next;
        cur->Next = cur->Next->Next;
        m_Length--;
    }
private:
    Node* m_DummyHead;
    int m_Length;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */