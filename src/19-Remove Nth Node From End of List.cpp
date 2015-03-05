// Source : https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : Javier Liu
// Date   : 2015-03-01

/********************************************************************************** 
* 
* Given a linked list, remove the nth node from the end of list and return its head.
* 
* For example,
* Given linked list: 1->2->3->4->5, and n = 2.
* After removing the second node from the end, the linked list becomes 1->2->3->5.
* 
* Note:
* Given n will always be valid.
* Try to do this in one pass.
*          
* Solution: Use two pointer, one is for head, and the other moves forward n step.
*           Then two pointer move together, when reach the end, the first one is the nth node from end.
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
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || n <= 0) 
        {
            return NULL;
        }
        ListNode* pHead =  new ListNode(0);
        pHead->next = head;
        
        ListNode* pFirst = pHead;
        ListNode* pSecond = pHead;
        int step = n;
        while (step > 0)
        {
            if (pSecond->next == NULL) 
            {
                return head;
            }
            pSecond = pSecond->next;
            --step;
        }
        while (pSecond->next != NULL)
        {
            pSecond = pSecond->next;
            pFirst = pFirst->next;
        }
        pFirst->next = pFirst->next->next;
        return pHead->next;
    }
};