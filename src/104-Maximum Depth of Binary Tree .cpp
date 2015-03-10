// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : Javier Liu
// Date   : 2015-03-10

/********************************************************************************** 
* 
* Given a binary tree, find its maximum depth.
* The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
private:
    int iMaxDepth = 0;
public:
    void PreorderTraverse(TreeNode *rNode, int iDepth)
    {
        if (rNode == NULL)
            return;
        iDepth += 1;
        iDepth > iMaxDepth ? iMaxDepth=iDepth: iMaxDepth;
        PreorderTraverse(rNode->left, iDepth);
        PreorderTraverse(rNode->right, iDepth);
        return;
    }
    int maxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
            
        PreorderTraverse(root, 0);
        return iMaxDepth;
    }
};