// Source : https://leetcode.com/problems/symmetric-tree/
// Author : Javier Liu
// Date   : 2015-03-10

/********************************************************************************** 
* 
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
* For example, this binary tree is symmetric:
*                       1
*                      / \
*                     2   2
*                    / \ / \
*                   3  4 4  3                            
*
* Solution: PreOrderTraverse, mark the max depth when traverse.
*              
**********************************************************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool CompareTwoChild(TreeNode *rLeft, TreeNode *rRight)
    {
        if (rLeft == NULL && rRight == NULL)
            return true;
        else if (rLeft == NULL || rRight == NULL)
            return false;
        if (rLeft->val != rRight->val)
            return false;
        if (!CompareTwoChild(rLeft->left, rRight->right))//compare outward branch
            return false;
        if (!CompareTwoChild(rLeft->right, rRight->left))//compare inward branch
            return false;
        return true;
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        return CompareTwoChild(root->left, root->right);
    }
};