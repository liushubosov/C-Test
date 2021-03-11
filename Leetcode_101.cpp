/*
* 101. 对称二叉树
*
给定一个二叉树，检查它是否是镜像对称的。

* 
* 解题思路： 
*   
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
    bool isSymmetric(TreeNode* root) {
        
        return traverse(root,root);
    }
    
    bool traverse(TreeNode* p1, TreeNode* p2)
    {
        if(!p1 && !p2) return true;
        if(!p1 || !p2) return false;
        
        return (p1->val == p2->val) && traverse(p1->left,p2->right) 
            && traverse(p1->right,p2->left);
    }
    
};