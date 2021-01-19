/*
* 993. 二叉树的堂兄弟节点
*
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。

如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。

我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。

只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。

示例：
输入：root = [1,2,3,4], x = 4, y = 3
输出：false

输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
输出：true

限制：
    二叉树的节点数介于 2 到 100 之间。
    每个节点的值都是唯一的、范围为 1 到 100 的整数。
* 
* 解题思路： 
*   广度优先遍历，找到两个节点的深度和父节点
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
private:
    int deep1, deep2;
    TreeNode* prev1, * prev2;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        deep1 = -2;
        deep2 = -1;
        prev1 = nullptr;
        prev2 = nullptr;
        nfs(nullptr, root, x, y, 0);
        return deep1 == deep2 && prev1 != prev2;
    }

    void nfs(TreeNode* parent, TreeNode* root, int x, int y, int deep) {
        if (!root)
            return;

        if (root->val == x)
        {
            deep1 = deep;
            prev1 = parent;
        }
        else if (root->val == y)
        {
            deep2 = deep;
            prev2 = parent;
        }
        else{
            nfs(root, root->left, x, y, deep + 1);
            nfs(root, root->right, x, y, deep + 1);
        }
    }
};