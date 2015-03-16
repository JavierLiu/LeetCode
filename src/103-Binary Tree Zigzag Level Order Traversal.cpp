// Source : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author : Javier Liu
// Date   : 2015-03-16

/********************************************************************************** 
* 
* Given a binary tree, return the zigzag level order traversal of its nodes' values. 
* (ie, from left to right, then right to left for the next level and alternate between).
* For example, Given binary tree {3,9,20,#,#,15,7}:
*                       3
*                      / \
*                     9  20
*                        / \
*                       15  7                            
* return its zigzag level order traversal as:
* [
*  [3],
*  [20,9],
*  [15,7]
* ]
*
* Solution: Just Like 102, but insert at the beginning/end by rotate
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
    void ZigtagTraverse(TreeNode *rNode, int iDepth)
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
            if (iDepth % 2 == 0)
                vecResult[iDepth].push_back(rNode->val);
            else
                vecResult[iDepth].insert(vecResult[iDepth].begin(), rNode->val);
        }
        ZigtagTraverse(rNode->left, iDepth+1);
        ZigtagTraverse(rNode->right, iDepth+1);
        return;
    }
    vector< vector<int> > zigzagLevelOrder(TreeNode *root) {
        vecResult.clear();
        if (root == NULL)
            return vecResult;

        ZigtagTraverse(root, 0);
        return vecResult;
    }
};