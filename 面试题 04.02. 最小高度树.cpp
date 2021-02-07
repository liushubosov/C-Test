/*
* 面试题 04.02. 最小高度树
*
给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。

* 
* 解题思路： 
*   采用数组二分法，递归创建树节点
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }

    TreeNode* dfs(vector<int>& nums, int L, int R){
        if(L > R)   return nullptr;
        int mid = L + (R-L)/2;
        TreeNode *p = new TreeNode(nums[mid]);
        p->left = dfs(nums, L, mid-1);
        p->right = dfs(nums, mid+1, R);
        return p;
    }
};