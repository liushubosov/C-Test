/*
* 501. 二叉搜索树中的众数
*
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],
返回[2].

提示：如果众数超过1个，不需考虑输出顺序
* 
* 解题思路： 
*   中根次序遍历，相同的值会紧邻着，只要判断相邻的值相等，计算相等值的数量。
*   因为要使用递归调用，所以需要把数组，前一个相等值，前一个相等值的数量，当前值的数量，全部抽到外边，作为成员变量。
*   0. 初始化时， 走 Step3，因为 curNum != prevNum(0),  curCount(1) > prevCount(0)
*   1. 当前值的数量小于 prevCount, 忽略
*   2. 当前值的数量等于 prevCount, 当前值存入数组
*   3. 当前值的数量大于 prevCount, 重置数组，当前值存入数组,prevCount = curCount
*/

class Solution {
public:
    vector<int> res;
    int maxCount, base, curCount;

    void checkNum(int n){
        if(n == base){
            curCount++;
        }else{
            base = n;
            curCount = 1;
        }

        if(curCount == maxCount)
            res.push_back(base);
        else if(curCount > maxCount){
            //res = vector<int> {base};
            res.clear();
            res.push_back(base);
            maxCount = curCount;
        }
    }

    void loopNode(TreeNode* p){
        if(p){
            loopNode(p->left);
            checkNum(p->val);
            loopNode(p->right);
        }
    }

    vector<int> findMode(TreeNode* root) {
        loopNode(root);
        return res;
    }   
};