// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author : Javier Liu
// Date   : 2015-03-15

/********************************************************************************** 
* 
* Follow up for problem "Populating Next Right Pointers in Each Node".
* What if the given tree could be any binary tree? Would your previous solution still work?
* 
* Note:
*       You may only use constant extra space.
* 
* For example, Given the following perfect binary tree,
*                       1                                     1 => null
*                     /  \                                   /  \
*                    2    3            ======>              2 => 3 => null
*                   / \    \                               / \    \
*                  4  5     7                             4=> 5 => 7 => null
*
* Solution: 1. connect child to its right brother(brother/cousin) when traverse
*           2. Traverse right child firstly, then left child. It will benefit for left child to find its cousin. 
*              
**********************************************************************************/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    TreeLinkNode* GetCousin(TreeLinkNode *rNode)
    {
        if (rNode == NULL)
            return NULL;
        TreeLinkNode* pTemp = rNode;    
        while (pTemp)
        {
            if (pTemp->left != NULL)
                return pTemp->left;
            else if (pTemp->right != NULL)
                return pTemp->right;
            pTemp = pTemp->next;
        }
        return NULL;
    }
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        if (root->left != NULL)
        {
            if (root->right != NULL)
                root->left->next = root->right;
            else 
                root->left->next = GetCousin(root->next);
        }
        
        if (root->right != NULL)
        {
            root->right->next = GetCousin(root->next);
        }
        connect(root->right);
        connect(root->left);
    }
};