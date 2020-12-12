/*
* 671. 二叉树中第二小的节点
*
给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。
如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。
更正式地说，root.val = min(root.left.val, root.right.val) 总成立。
给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

提示：
    树中节点数目在范围 [1, 25] 内
    1 <= Node.val <= 231 - 1
    对于树中每个节点 root.val == min(root.left.val, root.right.val)
* 
*
* 
* 解题思路： 
*   递归，从上往下一层层遍历 ，广度优先遍历
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
 //因为不是查找二叉树，不能确定 左子树的值小于等于右子树的值
//但是越上层，值越小，所以应该使用广度优先遍历
//root 就是最小节点
//接下来就是查找第二小节点
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        int res = INT_MAX;
        bool bFlag = false;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty())
        {
            TreeNode* p = myQueue.front();
            myQueue.pop();
            if(!p)
                continue;
            if(p->val > root->val)
            {  //找到了比 root 大的节点，不再遍历它的子节点。但是同层次可能有多个符合条件的节点， 使用 min()
                bFlag = true;    
                res = min(res, p->val);
            }
            else
            {
                myQueue.push(p->left);
                myQueue.push(p->right);
            }
        }

        return bFlag?res:-1;
    }
};