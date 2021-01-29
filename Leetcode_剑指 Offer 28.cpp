/*
* 剑指 Offer 28. 对称的二叉树
*
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

示例 1：
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

限制：
    0 <= 节点个数 <= 1000

注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/
* 
* 解题思路： 
*   1. 使用队列迭代树
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

//1. 使用队列迭代树
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        queue<TreeNode*> myqueue1;
        queue<TreeNode*> myqueue2;
        myqueue1.push(root->left);
        myqueue2.push(root->right);
        while(!myqueue1.empty()){
            TreeNode* p1 = myqueue1.front();
            TreeNode* p2 = myqueue2.front();
            myqueue1.pop();
            myqueue2.pop();
            if(p1 && !p2 || (!p1 && p2))
                return false;
            else if(p1 && p2){
                if(p1->val != p2->val)
                    return false;
                myqueue1.push(p1->left);
                myqueue1.push(p1->right);
                myqueue2.push(p2->right);
                myqueue2.push(p2->left);
            }
        }
        return true;
    }

};


//1.2 队列的改版
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        queue<TreeNode*> myqueue;
        myqueue.push(root->left);
        myqueue.push(root->right);
        while(!myqueue.empty()){
            TreeNode* p1 = myqueue.front();
            myqueue.pop();
            TreeNode* p2 = myqueue.front();
            myqueue.pop();
            if(!p1 && !p2)  continue;
            if(!p1 || !p2 || p1->val != p2->val)    return false;
            myqueue.push(p1->left);
            myqueue.push(p2->right);
            myqueue.push(p1->right);
            myqueue.push(p2->left);                       
        }
        return true;
    }

};

/**
 * 2. 使用递归
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        return checkNode(root->left, root->right);
    }

    bool checkNode(TreeNode* L, TreeNode* R){
        if(!L && !R) return true;
        if(!L  || !R || L->val != R->val)    return false;
        return checkNode(L->left,R->right) && checkNode(L->right, R->left);
    }

};