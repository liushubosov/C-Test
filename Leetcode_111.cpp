/*
* 111. 二叉树的最小深度
*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

提示：
树中节点数的范围在 [0, 105] 内
-1000 <= Node.val <= 1000

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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);   
        if(l == 0 && r ==0) return 1;
        if(l == 0 || r ==0) return max(l,r)+1;
        return min(l,r) + 1;
    }
    
};