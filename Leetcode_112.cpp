/*
* 112. 路径总和
*
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
叶子节点 是指没有子节点的节点。

提示：
树中节点的数目在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        bool bFlag = false;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* cur = que.front();
            if(!cur->left && !cur->right)
            {
                if(cur->val == sum)
                    return true;
            }            
            if(cur->left)
            {
                cur->left->val += cur->val;
                que.push(cur->left);
            }
            if(cur->right)
            {
                cur->right->val += cur->val;
                que.push(cur->right);
            }
            que.pop();
        }             
        return false;
    }     
};