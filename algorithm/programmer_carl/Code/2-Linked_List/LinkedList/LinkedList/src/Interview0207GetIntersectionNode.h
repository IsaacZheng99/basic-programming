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

class SolutionInterview0207
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode* cur = headA;
        int sizeA = 0;
        while (cur)
        {
            sizeA++;
            cur = cur->next;
        }
        cur = headB;
        int sizeB = 0;
        while (cur)
        {
            sizeB++;
            cur = cur->next;
        }

        ListNode* curA = headA;
        ListNode* curB = headB;
    
        int diff = sizeA > sizeB ? (sizeA - sizeB) : (sizeB - sizeA);
        if (sizeA > sizeB)
        {
            while (diff--)
                curA = curA->next;
        }
        else
        {
            while (diff--)
                curB = curB->next;
        }

        while (curA and curB)
        {
            if (curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;

    }
};