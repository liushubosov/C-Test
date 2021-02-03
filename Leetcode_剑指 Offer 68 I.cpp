/*
* 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

限制：
    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉搜索树中。

注意：本题与主站 235 题相同：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
* 
* 解题思路： 
*   遍历，如果p，q在当前节点的同一侧，继续遍历；如果分别在两侧，找到目标
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};


class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        TreeNode *res = root;
        while(true){
            if(res->val > p->val && res->val > q->val)
                res = res->left;
            else if(res->val < p->val && res->val < q->val)
                res = res->right;
            else
                break;
        }
        return res;
    }
};