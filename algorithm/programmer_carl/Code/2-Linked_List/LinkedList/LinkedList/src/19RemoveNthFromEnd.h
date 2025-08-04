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


class Solution19
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        
        while (n--)
            fast = fast->next;

        
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        ListNode* result = dummyHead->next;
        delete dummyHead;

        return result;
    }
};


//class Solution19
//{
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n)
//    {
//        int size = 0;
//        ListNode* cur = head;
//        while (cur)
//        {
//            size++;
//            cur = cur->next;
//        }
//
//        int index = size - n;
//
//        ListNode* dummyHead = new ListNode(0, head);
//        ListNode* pre = dummyHead;
//        cur = dummyHead->next;
//        while (index--)
//        {
//            pre = cur;
//            cur = cur->next;
//        }
//        pre->next = cur->next;
//
//        ListNode* result = dummyHead->next;
//        delete dummyHead;
//        return result;
//    }
//};