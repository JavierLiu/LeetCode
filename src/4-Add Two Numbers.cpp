// Source : https://oj.leetcode.com/problems/add-two-numbers/
// Author : Javier Liu
// Date   : 2015-03-01

/********************************************************************************** 
*
* You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit.
* Add the two numbers and return it as a linked list.
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
* 
* Solution: Pay highly attention to 进位. Especially for the last one, such as 999+1=1000
*
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
	int GetColumnSum(ListNode* p1, ListNode* p2, bool& isCarry)
	{	
		//pre-condition: p1 and p2 will not be all NULL, only one is NULL
		int temp = 0;
		if (p1 != NULL)
			temp += p1->val;
		if (p2 != NULL)
			temp += p2->val;
		if (isCarry)
		{
			isCarry = false;
			temp += 1;
		}
		if (temp >= 10)
		{
			temp = temp % 10;
			isCarry = true;
		}
		return temp;
	}
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (l1 == NULL || l2 == NULL)
		{
			return NULL;
		}
		ListNode *pList, *pHead;
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		bool isCarry(false);
		pHead = pList = new ListNode(GetColumnSum(p1, p2, isCarry));
		p1 = p1->next;
		p2 = p2->next;
		while (p1 != NULL && p2 != NULL)
		{
			ListNode *pNode = new ListNode(GetColumnSum(p1, p2, isCarry));
			pList->next = pNode;
			pList = pList->next;
			p1 = p1->next;
			p2 = p2->next;
		}		
		p1 == NULL ? p1 = p2: p1; //only use p1 to maintain the left part
		while (p1 != NULL)
		{
			ListNode *pNode = new ListNode(GetColumnSum(p1, NULL, isCarry));
			pList->next = pNode;
			pList = pList->next;
			p1 = p1->next;
		}
		if (isCarry)
		{
			ListNode *pNode = new ListNode(1);
			pList->next = pNode;
			pList = pList->next;
		}
		return pHead;
	}
};