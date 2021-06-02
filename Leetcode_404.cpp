/*
* 404. 左叶子之和
*
计算给定二叉树的所有左叶子之和。

* 
* 解题思路： 
*   递归
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int left = 0;
        if(root->left){
            if(!root->left->left && !root->left->right)
                left = root->left->val;
            else
                left += sumOfLeftLeaves(root->left);
        }
        if(root->right){
            left += sumOfLeftLeaves(root->right);
        }
        return left;
    }
};
