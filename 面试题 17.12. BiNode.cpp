/*
* 面试题 17.12. BiNode
*
二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。
实现一个方法，把二叉搜索树转换为单向链表，要求依然符合二叉搜索树的性质，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。
返回转换后的单向链表的头节点。
注意：本题相对原题稍作改动

示例：
输入： [4,2,5,1,3,null,6,0]
输出： [0,null,1,null,2,null,3,null,4,null,5,null,6]

提示：
节点数量不会超过 100000。
* 
* 解题思路： 
*   普通的修改，是为了遍历这个树，所以只需要修改左边的树
*   这道题还需要修改右边的树，把一个右节点 parent 的孩子节点 leftchild,rightchild 做如下修改
*   leftchild 替换 parent 的位置: 
        parent->parent->right = leftchild
        leftchild->right = parent
        parent->left = null
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
    TreeNode* convertBiNode(TreeNode* root) {
        TreeNode *res = nullptr;
        TreeNode *parent = nullptr;
        while(root){
            if(root->left){
                TreeNode *prev = root->left;
                while(prev->right){
                    prev = prev->right;
                }
                if(parent) //右子树的父节点改为指向右子树的左子节点
                    parent->right = root->left;               
                prev->right = root;              
                TreeNode *tmp = root;
                root = root->left;
                tmp->left = nullptr;
            }else{
                if(!res) //最左节点就是根节点
                    res = root;
                parent = root; //右子树的父节点需要保存
                root = root->right;
            }
        }

        return res;
    }
};