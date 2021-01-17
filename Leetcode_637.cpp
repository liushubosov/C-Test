/*
* 637. 二叉树的层平均值
*
* 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。
* 

*
* 注意: 节点值的范围在32位有符号整数范围内。
* 
* 解题思路： 
*   1. 递归，使用两个数组，一个存每层的值的和，另一个存层节点数量，最后遍历数组， sum/count
*   2. 迭代，使用队列，每次迭代都把一层的值全部 pop 出来，计算 sum/count
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

//递归
/*
提交记录
65 / 65 个通过测试用例
状态：通过
执行用时: 28 ms
内存消耗: 22.6 MB
语言： cpp
*/

class Solution {
public:
    vector<double> res;
    vector<int> countList;
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        for(int i=0;i < res.size();++i){
            res[i] = res[i] / countList[i];
        }
        return res;
    }

    void dfs(TreeNode* p, int level){
        if(!p)
            return;
        if(level < res.size()){
            res[level] += p->val;
            ++countList[level];
        }
        else{
            res.push_back(p->val);
            countList.push_back(1);
        }
        level++;
        dfs(p->left, level);
        dfs(p->right, level);
    }
};



/*
提交记录
65 / 65 个通过测试用例
状态：通过
执行用时: 28 ms
内存消耗: 22.3 MB
语言： cpp
*/

//迭代
class Solution2 {
public:
    
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)
            return {};
        vector<double> res;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty())
        {
            double sum = 0;
            int s = myQueue.size();
            for(int i=0;i < s;++i)
            {
                TreeNode* p = myQueue.front();
                myQueue.pop();
                sum += p->val;
                if(p->left)
                    myQueue.push(p->left);  
                if(p->right)
                    myQueue.push(p->right);                                        
            }
            res.push_back(sum/s);
        }      
        return res;
    }
};
