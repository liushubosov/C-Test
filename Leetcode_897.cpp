/*
* 897. 递增顺序查找树
*
给你一个树，请你 按中序遍历 重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。

注意：
    给定树中的结点数介于 1 和 100 之间。
    每个结点都有一个从 0 到 1000 范围内的唯一整数值。
* 
* 解题思路： 
*   1.迭代
*   2.递归
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
class Solution1 {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = nullptr;
        TreeNode* parent = nullptr;
        while(root){//当前节点: root
            //当前节点有左子树root->left，那就把当前节点及右子树整个挂在 左子树的最右节点下。root->left->right = root
            if(root->left){
                //遍历找到左子树的最右节点
                TreeNode* prev = root->left;
                while(prev->right){
                    prev = prev->right;
                }
                //把当前节点挂在最右节点下，作为它的右子树
                prev->right = root;
                //当前节点存在父节点，那么使父节点的右孩子节点 指向 当前节点的左孩子节点
                if(parent)
                    parent->right = root->left;
                //当前节点指向左孩子节点，并把当前节点的左孩子节点变为空， 准备下一次的迭代
                TreeNode* tmp = root;              
                root = root->left;
                tmp->left = nullptr;
            }else{
                //当前节点没有左子树，说明已经到最左节点，根节点就是它了
                if(res == nullptr)
                    res = root;
                //当前节点指向右孩子节点，并保存当前节点为父节点， 准备下一次的迭代
                parent = root;
                root = root->right;
            }
        }
        return res;
    }
};


class Solution2 {
private:
    TreeNode* prev;
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode();
        prev = res;
        loopNode(root);
        return res->right;
    }

    void loopNode(TreeNode* p){
        if(!p)
            return;
        loopNode(p->left);
        p->left = nullptr;
        prev->right = p;
        prev = p;
        loopNode(p->right);
    }
};