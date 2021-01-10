/*
* 872. 叶子相似的树
*
请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

注意：
    给定的两棵树可能会有 1 到 200 个结点。
    给定的两棵树上的值介于 0 到 200 之间。
* 
* 解题思路： 
*   使用栈迭代两个树，找出叶子，比较
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> mylist1, mylist2;
        loopNode(root1, mylist1);
        loopNode(root2, mylist2);
        return mylist1 == mylist2;
    }

    void loopNode(TreeNode* root, vector<int> &mylist){
        stack<TreeNode*> mystack;
        mystack.push(root);
        while(!mystack.empty()){
            TreeNode* p = mystack.top();
            mystack.pop();
            if(p->right)
                mystack.push(p->right);
            else{
                if(!p->left)
                    mylist.push_back(p->val);
            }
            if(p->left)
                mystack.push(p->left);             
        }
    }
};