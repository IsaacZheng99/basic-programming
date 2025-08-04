#pragma once

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};


class Solution26
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        
        while (cur->next && cur->next->next)
        {
            ListNode* temp1 = cur->next;
            ListNode* temp2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = temp1;
            temp1->next = temp2;
            
            cur = temp1;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

//class Solution26
//{
//public:
//    ListNode* swapPairs(ListNode* head)
//    {
//        if (!head || !head->next)
//            return head;
//
//        ListNode* first = head;
//        ListNode* second = head->next;
//        ListNode* newHead = second;
//
//        while (first && second)
//        {
//            ListNode* temp = second->next;
//
//            if (!temp || !temp->next)
//            {
//                first->next = temp;
//                second->next = first;
//                break;
//            }
//            else
//            {
//                first->next = temp->next;
//                second->next = first;
//                first = temp;
//                second = temp->next;
//
//            }
//        }
//        return newHead;
//    }
//};