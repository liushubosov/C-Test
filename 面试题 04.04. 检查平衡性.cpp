/*
* 面试题 04.04. 检查平衡性
*
实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。

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
    bool res;
    bool isBalanced(TreeNode* root) {
        res = true;
        dfs(root);
        return res;
    }

    int dfs(TreeNode *root){
        if(!root || !res)   return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        if(abs(L-R) > 1)
            res = false;
        return max(L,R)+1;
    }
};
