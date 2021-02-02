/*
* 剑指 Offer 55 - I. 二叉树的深度
*
输入一棵二叉树的根节点，求该树的深度。
从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

限制：
    节点总数 <= 10000

注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
* 
* 解题思路： 
*   当前节点深度等于最深子节点的深度加1
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
    
    int maxDepth(TreeNode* root) {
        if(!root)   return 0;     
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};