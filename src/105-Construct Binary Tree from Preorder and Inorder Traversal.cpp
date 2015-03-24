// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : Javier Liu
// Date   : 2015-03-24

/********************************************************************************** 
* 
* Given preorder and inorder traversal of a tree, construct the binary tree.
*
* Note:
* You may assume that duplicates do not exist in the tree.
* 
* Solution: 1. Make the root from the 1st element of preorder.
*           2. Use root to divide the inorder into two parts, left and right
*           3. Get the length of left and right, then map to preorder
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
    TreeNode *BuildTree(vector<int> &preorder, unsigned int _iterPreBegin, unsigned int _iterPreEnd,
                        vector<int> &inorder, unsigned int _iterInBegin, unsigned int _iterInEnd) 
    {
        if (_iterPreEnd==_iterPreBegin || _iterInBegin==_iterInEnd)
        {
            return NULL;
        }

        TreeNode *pNode = new TreeNode(preorder[_iterPreBegin]);

        unsigned int iterRoot = _iterInBegin;
        for (unsigned int i = _iterInBegin; i != _iterInEnd; ++i)
        {
            if (inorder[i] == pNode->val)
            {
                iterRoot = i;
                break;
            }
        }

        //cut the left of inorder 
        unsigned int iterLeftInBegin, iterLeftInEnd, iterLeftPreBegin, iterLeftPreEnd;
        //construct the inorder list of left child.
        iterLeftInBegin = _iterInBegin;
        iterLeftInEnd = iterRoot;
        //construct the preorder list of left child
        iterLeftPreBegin = _iterPreBegin + 1;
        iterLeftPreEnd = _iterPreBegin + 1 + (iterRoot - _iterInBegin);

        //cut the right of inorder
        unsigned int iterRightInBegin, iterRightInEnd, iterRightPreBegin, iterRightPreEnd;
        //construct the inorder list of right child.
        iterRightInBegin = iterRoot + 1;
        iterRightInEnd = _iterInEnd;
        //construct the preorder list of right child
        iterRightPreBegin = iterLeftPreEnd;
        iterRightPreEnd = _iterPreEnd;

        pNode->left = BuildTree(preorder, iterLeftPreBegin, iterLeftPreEnd, 
                                inorder, iterLeftInBegin, iterLeftInEnd);

        pNode->right = BuildTree(preorder, iterRightPreBegin, iterRightPreEnd, 
                                 inorder, iterRightInBegin, iterRightInEnd);

        return pNode;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size()!=inorder.size() || preorder.size()==0 || inorder.size()==0)
        {
            return NULL;
        }

        return BuildTree(preorder, 0, preorder.size(), inorder, 0, preorder.size());
    }
};