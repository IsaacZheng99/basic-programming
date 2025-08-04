#pragma once


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        int lengthA = 0;
        int lengthB = 0;
        ListNode* cur = headA;
        while (cur)
        {
            lengthA++;
            cur = cur->next;
        }
        ListNode* cur = headB;
        while (cur)
        {
            lengthB++;
            cur = cur->next;
        }

        ListNode* slow = nullptr;
        ListNode* fast = nullptr;
        int diff = 0;
        if (lengthA >= lengthB)
        {
            slow = headB;
            fast = headA;
            diff = lengthA - lengthB;
        }
        else
        {
            slow = headA;
            fast = headB;
            diff = lengthB - lengthA;
        }

        for (int i = 0; i < diff; i++)
            fast = fast->next;

        while (slow && fast)
        {
            if (slow == fast)
                return slow;
            slow = slow->next;
            fast = fast->next;
        }

        return nullptr;
    }
};