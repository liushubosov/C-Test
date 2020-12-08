/*
* 653. 两数之和 IV - 输入 BST
*
* 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
* 
*
* 
* 解题思路： 
*   Solution 1. 迭代，再加上用 set 存数值，每次迭代都判断当前节点的值 Set 中是否存在符合的值。
*   Solution 2. 先使用递归将中跟遍历的值存入 vector,  然后 两个指针指向 vector 的头和尾，
*       如果 sum > k , right--; sum < k, left++; sum == k, return true
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
//迭代
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        unordered_set<int> mySet;
        stack<TreeNode*> myStack;
        myStack.push(root);
        while(!myStack.empty())
        {
            TreeNode* p = myStack.top();
            myStack.pop();
            if(p)
            {
                if(mySet.count(p->val) != 0)
                    return true;
                else
                {
                    mySet.insert(k - p->val);
                }
                myStack.push(p->left);
                myStack.push(p->right);
            }
        }
        return false;
    }
};


//递归
class Solution2 {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> vtr;
        dfs(root, vtr);
        int left=0, right=vtr.size()-1, sum=0;
        while(left < right)
        {
            sum = vtr[left] + vtr[right];
            if(sum == k)
                return true;
            else if(sum < k)
                left++;
            else
                right--;
        }     
        return false;
    }

    void dfs(TreeNode* p, vector<int>& vtr)
    {
        if(!p)
            return;
        dfs(p->left, vtr);
        vtr.push_back(p->val);
        dfs(p->right, vtr);
    }
};