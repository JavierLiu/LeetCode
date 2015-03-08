// Source : https://oj.leetcode.com/problems/path-sum/
// Author : Javier Liu
// Date   : 2015-03-08

/********************************************************************************** 
* 
* Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
* For example:
* Given the below binary tree and sum = 22,
*             5
*            / \
*           4   8
*          /   / \
*         11  13  4
*        /  \      \
*       7    2      1
* return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
* 
* Solution: 1. Pre-Order traverse.
*			2. Must a root-to-leaf path. Need to judge if the node is leaf
*			3. Negative number
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
	bool IsLeaf(TreeNode *rNode)
	{
		return (rNode!=NULL && rNode->left==NULL && rNode->right==NULL)?true:false;
	}
	bool PreorderTraverse(TreeNode *rNode, int iSum)
	{
		if (rNode == NULL)
			return false;
		if (iSum == rNode->val && IsLeaf(rNode))
			return true;
		if (PreorderTraverse(rNode->left, iSum-rNode->val))
			return true;
		if (PreorderTraverse(rNode->right, iSum-rNode->val))
			return true;
		return false;
	}
public:
    bool hasPathSum(TreeNode *root, int sum) {
		if (root == NULL)
			return false;
		return PreorderTraverse(root, sum);
    }
};