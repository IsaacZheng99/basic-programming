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

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution203
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* cur = dummyNode;
        while (cur->next)
        {
            if (cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
            else
                cur = cur->next;

        }
        head = dummyNode->next;
        delete dummyNode;

        return head;
    }
};