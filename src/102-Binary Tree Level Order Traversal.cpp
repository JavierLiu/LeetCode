// Source : https://leetcode.com/problems/binary-tree-level-order-traversal/
// Author : Javier Liu
// Date   : 2015-03-11

/********************************************************************************** 
* 
* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
* For example, Given binary tree {3,9,20,#,#,15,7}:
*                       3
*                      / \
*                     9  20
*                        / \
*                       15  7                            
* return its level order traversal as:
* [
*  [3],
*  [9,20],
*  [15,7]
* ]
*
* Solution: PreOrderTraverse, mark the current depth for adding the element to the right vector.
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
    vector< vector<int> > vecResult;
public:
    void TraverseChild(TreeNode *rNode, int iDepth)
    {
        if (rNode == NULL)
            return;
        
        if (vecResult.size() <= iDepth)
        {
            vector<int> vec;
            vec.push_back(rNode->val);
            vecResult.push_back(vec);
        }
        else
        {
            vecResult[iDepth].push_back(rNode->val);
        }
        TraverseChild(rNode->left, iDepth+1);
        TraverseChild(rNode->right, iDepth+1);
        return;
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
        vecResult.clear();
        if (root == NULL)
            return vecResult;
        
        TraverseChild(root, 0);
        return vecResult;
    }
};