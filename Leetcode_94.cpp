/*
* 94. 二叉树的中序遍历
*
给定一个二叉树的根节点 root ，返回它的 中序 遍历。

提示：
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100

* 
* 解题思路： 
*   递归或者迭代,第三种方法，移动树的位置，使树节点全部没有左子节点
*/

class Solution {
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root){
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
};


class Solution2 {   
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> myStack;
        while(root || !myStack.empty()){
            while(root){
                myStack.push(root);
                root = root->left;
            }
            TreeNode* p = myStack.top();
            myStack.pop();
            res.push_back(p->val);
            root = p->right;
        }
        return res;
    }

};


class Solution3 {   
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        while(root){          
            if(root->left){
                TreeNode *prev = root->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = root;
                TreeNode* tmp = root;
                root = root->left;
                tmp->left = nullptr;
            }else{
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }

};