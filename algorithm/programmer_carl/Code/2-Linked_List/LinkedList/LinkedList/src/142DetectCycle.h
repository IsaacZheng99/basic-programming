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
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meet = nullptr;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                meet = slow;
                break;
            }
        }
        ListNode* cur = head;
        while (cur && meet)
        {
            cur = cur->next;
            meet = meet->next;
            if (cur && cur == meet)
                return cur;
        }
        return nullptr;
    }
};