/*
* 938. 二叉搜索树的范围和
*
给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。

示例：
输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
输出：32

限制：
    树中节点数目在范围 [1, 2 * 104] 内
    1 <= Node.val <= 105
    1 <= low <= high <= 105
    所有 Node.val 互不相同

* 
* 解题思路： 
*   1. 修剪树，变为一个单调增长的树，左子树全为空，然后开始遍历
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        while(root){
            if(root->left){
                TreeNode *p = root->left;
                while(p->right){
                    p = p->right;
                }
                p->right = root;
                TreeNode* tmp = root;
                root = root->left;
                tmp->left = nullptr;
            }else{
                if(root->val > high)
                    break;
                if(root->val >= low)
                    res += root->val;
                root = root->right;
            }
        }
        return res;
    }
};