/*
* 108. 将有序数组转换为二叉搜索树
*
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

提示：
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 按 严格递增 顺序排列

* 
* 解题思路： 
*   
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
        int len = nums.size() ;
        if(len == 0) return NULL;
        return buildTree(nums,0,len-1);
    }
    
    TreeNode* buildTree(vector<int>& nums, int b, int e)
    {
        if(b > e)
            return NULL;       
        int med = b + (e - b) / 2;
        TreeNode* root = new TreeNode(nums[med]);
        root->left = buildTree(nums, b, med-1);
        root->right = buildTree(nums, med+1, e);
        return root;
    }
};