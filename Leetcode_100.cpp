/*
* 100. 相同的树
*
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

提示：
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        return trevel(p,q);        
    }
    
    bool trevel(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;              
        if(p->val != q->val) return false;        
        if(trevel(p->left,q->left))
            return trevel(p->right,q->right);
        return false;
    }
};