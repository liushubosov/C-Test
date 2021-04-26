/*
* 257. 二叉树的所有路径
*
给定一个二叉树，返回所有从根节点到叶子节点的路径。
说明: 叶子节点是指没有子节点的节点。

说明:

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vtr;
        if(root){
            string strTmp = to_string(root->val); 
            if(!root->left && !root->right){
                vtr.push_back(strTmp);
            }else{
                vector<string> vtr1;
                vector<string> vtr2;
                vtr1 = binaryTreePaths(root->left);
                vtr2 = binaryTreePaths(root->right);
                
                for(int i=0;i<vtr1.size();++i){
                    vtr.push_back(strTmp + "->" + vtr1[i]);
                }

                for(int j=0;j < vtr2.size();++j){
                    vtr.push_back(strTmp + "->" + vtr2[j]);
                }
            }
        }
        return vtr;
    }
};