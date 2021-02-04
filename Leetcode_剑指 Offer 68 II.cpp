/*
* 剑指 Offer 68 - II. 二叉树的最近公共祖先
*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

限制：
    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉树中。

本题与主站 236 题相同：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
* 
* 解题思路： 
*   二叉树没有顺序，必须全部
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
    TreeNode *res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q){
        if(!root || res) return false;
        bool bFlag1 = dfs(root->left, p, q);
        bool bFlag2 = dfs(root->right, p, q);
        //当前节点的子节点匹配p,q，找到最近公共祖先
        if(bFlag1 && bFlag2)
        {
            res = root;
            return true;
        }
        //当前节点匹配要找的节点p
        if(root == p || root == q)
        {
            //当前节点的子节点匹配q，找到最近公共祖先
            if(bFlag1 || bFlag2)
                res = root;
            //当前节点的子节点不匹配q，还是返回 true
            return true;                   
        }else
            return bFlag1 || bFlag2;
    }
};