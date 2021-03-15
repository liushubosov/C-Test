/*
* 110. 平衡二叉树
*
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

提示：
树中的节点数在范围 [0, 5000] 内
-104 <= Node.val <= 104

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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return treeHigh(root) != -1;
    }
    
    int treeHigh(TreeNode* p)
    {
        if(!p) return 0;
        int lHigh = treeHigh(p->left);
        if(lHigh == -1) return -1;
        int rHigh = treeHigh(p->right); 
        if(rHigh == -1) return -1;
        if(abs(lHigh-rHigh) > 1) return -1;
        return max(lHigh,rHigh)+1;
    }
};