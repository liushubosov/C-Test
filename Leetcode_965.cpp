/*
* 965. 单值二叉树
*
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
只有给定的树是单值二叉树时，才返回 true；否则返回 false。


限制：
    给定树的节点数范围是 [1, 100]。
    每个节点的值都是整数，范围为 [0, 99] 。
* 
* 解题思路： 
*   1. 递归,
*   2. 迭代
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
private:
    int base;
public:
    bool isUnivalTree(TreeNode* root) {
        base = root->val;        
        return dfs(root);
    }
    bool dfs(TreeNode* root){
        if(!root) return true;
        if(root->val != base)
            return false;
        return dfs(root->left) && dfs(root->right);     
    }
};


class Solution2 {
public:
    bool isUnivalTree(TreeNode* root) {
        int base = root->val;
        stack<TreeNode*> mystack;
        mystack.push(root);
        while(!mystack.empty()){
            TreeNode* p = mystack.top();
            mystack.pop();
            if(p ){
                if(p->val != base)
                    return false;
                mystack.push(p->left);
                mystack.push(p->right);
            }
        }
        return true;
    }
};