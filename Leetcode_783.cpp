/*
* 783. 二叉搜索树节点最小距离
*
给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。

示例 1：
输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树节点对象(TreeNode object)，而不是数组。

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。

注意：
    二叉树的大小范围在 2 到 100。
    二叉树总是有效的，每个节点的值都是整数，且不重复。
    本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同
* 
* 解题思路： 
*   Solution1：按照中根次序遍历二叉树，把结果保存在数组里。遍历数组的相邻节点即可找出最小距离
*   Solution2：同样是中根次序遍历，不需要数组，只要在递归的时候传递前继节点的值，当前值减去前继值与当前的最小值比较。
*   Solution3：与方法二相同，改遍历为递归
*   Solution4：与方法三类似，但是不再使用栈，直接原地修改二叉树，使树中节点不再有左子节点，只有右子节点，类似排序后的数组，由小到大。
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

//Solution1
class Solution1 {
private:
    vector<int> mylist;
public:
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        loop(root);
        for(int i=1;i < mylist.size();i++){
            res = min(res, mylist[i] - mylist[i-1]);
        }
        return res;
    }

    void loop(TreeNode* p){
        if(p){
            loop(p->left);
            mylist.push_back(p->val);
            loop(p->right);
        }
    }
};

//Solution2
class Solution2 {
public:
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX, prev=-1;
        loop(root, prev, res);
        return res;
    }

    void loop(TreeNode* p, int& prev, int& res){
        if(p){
            loop(p->left, prev, res);
            if(prev != -1)
                res = min(res, p->val- prev);
            prev = p->val;
            loop(p->right, prev, res);
        }
    }
};

//Solution3
class Solution3 {
public:
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX, prev=-1;
        stack<TreeNode*> myStack;
        while(root || !myStack.empty()){
            while(root){
                myStack.push(root);
                root = root->left;
            }

            TreeNode* p = myStack.top();
            myStack.pop();
            if(prev != -1){
                res = min(res, p->val - prev);
            }
            prev = p->val;
            root = p->right;
        }
        return res;
    }
};

//Solution4
class Solution4 {
public:
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX, prev=-1;
        while(root){
            if(root->left){
                TreeNode* prev = root->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = root;
                TreeNode* tmp = root;
                root = root->left;
                tmp->left = nullptr;
            }else{
                if(prev != -1){
                    res = min(res, root->val-prev);
                }
                prev = root->val;
                root = root->right;
            }
        }
        return res;
    }
};