/*
* 剑指 Offer 32 - II. 从上到下打印二叉树 II
*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

限制：
    节点总数 <= 1000

注意：本题与主站 102 题相同：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

* 
* 解题思路： 
*   1. 广度优先遍历
*   2. 使用队列
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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root, 0);
        return res;

    }

    void bfs(TreeNode *p, size_t deep){
        if(!p)  return;
        for(size_t i=deep+1; i > res.size();--i){
            vector<int> newline;
            res.push_back(newline);
        }
        res[deep].push_back(p->val);
        bfs(p->left, deep+1);
        bfs(p->right, deep+1);
    }
};

class Solution2 {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)   return {};
        vector<vector<int>> res;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        while(!myqueue.empty()){    
            vector<int> mylist;
            for(int i=myqueue.size();i > 0;--i){
                TreeNode *p = myqueue.front();
                myqueue.pop();
                mylist.push_back(p->val);
                if(p->left)
                    myqueue.push(p->left);
                if(p->right)
                    myqueue.push(p->right);
            }
            res.push_back(mylist);
        }
        return res;
    }
};