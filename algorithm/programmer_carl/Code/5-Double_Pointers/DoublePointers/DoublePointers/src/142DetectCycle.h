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


class Solution142
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meet = nullptr;
        while (slow && fast && fast->next)
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
            if (cur == meet)
                return cur;
            cur = cur->next;
            meet = meet->next;
        }

        return nullptr;
    }
};