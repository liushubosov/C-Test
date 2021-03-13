/*
* 107. 二叉树的层序遍历 II
*
给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;         
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            vector<int> curList;
            int size = que.size();
            for(int i=0;i < size;++i)
            {
                TreeNode* cur = que.front();
                curList.push_back(cur->val);
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
                que.pop();
            }
            result.push_back(curList);
            
        }
        reverse(result.begin(),result.end());        
        return result;
    }
};