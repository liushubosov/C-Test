/*
* 669. 修剪二叉搜索树
*
给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
修剪树不应该改变保留在树中的元素的相对结构（即，如果没有被移除，原有的父代子代关系都应当保留）。 可以证明，存在唯一的答案。
所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

提示：
    树中节点数在范围 [1, 104] 内
    0 <= Node.val <= 104
    树中每个节点的值都是唯一的
    题目数据保证输入是一棵有效的二叉搜索树
    0 <= low <= high <= 104

* 
*
* 
* 解题思路： 
*   递归，从上往下一层层遍历 ，广度优先遍历
*   先检查父节点，然后检查子节点
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return root;
        if(root->val < low)
            return trimBST(root->right, low, high);
        else if(root->val > high)
            return trimBST(root->left, low, high);
        
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        return root;
    }
};


//使用队列迭代，但是在检查父节点的时候还是使用递归
class Solution2 {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* newRoot = new TreeNode(0, root, nullptr) ;
        queue<TreeNode*> myQueue;
        myQueue.push(newRoot);
        while(!myQueue.empty())
        {
            TreeNode* p = myQueue.front();
            myQueue.pop();
            if(!p)
                continue;
            if(p->left)
            {
                p->left = dfs(p->left,low,high);
                myQueue.push(p->left);
            }

            if(p->right)
            {
                p->right = dfs(p->right,low,high);
                myQueue.push(p->right);
            }
        }
        if(newRoot)
        {
            root = newRoot->left;
            delete newRoot;
            newRoot = nullptr;
        }
        return root;
    }

    TreeNode* dfs(TreeNode* p, int low, int high)
    {
        if(!p)
            return p;
        if(p->val < low)
            return dfs(p->right, low, high);
        else if(p->val > high)
            return dfs(p->left, low, high);
        else
            return p;

    }
};