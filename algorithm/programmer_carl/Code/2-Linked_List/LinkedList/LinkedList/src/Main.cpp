#include <iostream>
#include "142DetectCycle.h"


int main()
{
	ListNode* head = new ListNode(1);
	head->next = head;

	Solution s;
	ListNode* result = s.detectCycle(head);
	std::cout << result->val << std::endl;






}
