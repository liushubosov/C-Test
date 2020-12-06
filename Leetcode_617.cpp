/*
* 617. 合并二叉树
*
* 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
* 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

*
* 注意: 合并必须从两个树的根节点开始。
* 
* 解题思路： 
*   深度遍历
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 && !t2)
            return t1;
        else if(!t1 && t2)
            return t2;
        else if(!t1 && !t2)
            return t1;
        t1->val += t2->val;
        dfs(t1, t2);
        return t1;
    }

    void dfs(TreeNode* t1, TreeNode* t2){
        if(!t1->left && t2->left){
            t1->left = t2->left;
        }
        else if(t1->left && t2->left){
            t1->left->val += t2->left->val;
            dfs(t1->left, t2->left);
        }

        if(!t1->right && t2->right){
            t1->right = t2->right;
        }
        else if(t1->right && t2->right){
            t1->right->val += t2->right->val;
            dfs(t1->right, t2->right);
        }
    }
};