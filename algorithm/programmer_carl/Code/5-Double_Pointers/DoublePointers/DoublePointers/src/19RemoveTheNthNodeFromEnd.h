#pragma once


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};


class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* fast = dummyHead;
        while (n--)
            fast = fast->next;

        ListNode* slow = dummyHead;
        while (fast && fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        ListNode* result = dummyHead->next;
        delete dummyHead;

        return result;
    }
};