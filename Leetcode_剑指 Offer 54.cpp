/*
* 剑指 Offer 54. 二叉搜索树的第k大节点
*
给定一棵二叉搜索树，请找出其中第k大的节点。

限制：
    1 ≤ k ≤ 二叉搜索树元素个数

* 
* 解题思路： 
*   从最右节点开始遍历，k--, k==0的时候就是需要的值
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
    int res, n;
    int kthLargest(TreeNode* root, int k) {
        n = k;
        dfs(root);
        return res;
    }
    
    void dfs(TreeNode *p){
        if(!p )  return;
        dfs(p->right);
        if(n == 0) return;
        if(--n == 0){
           res = p->val;
           return;
        }
        dfs(p->left);
    }
};