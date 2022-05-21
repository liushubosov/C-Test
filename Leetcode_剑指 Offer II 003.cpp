//剑指 Offer II 003. 前 n 个数字二进制中 1 的个数
//给定一个非负整数 n ，请计算 0 到 n 之间的每个数字的二进制表示中 1 的个数，并输出一个数组。
//0 <= n <= 105
//本题与主站 338 题相同：https://leetcode-cn.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0)
            return {0};
        vector<int> vtrCount(n+1,0);
        vtrCount[1] = 1;
        
        for(int i = 2; i <= n; ++i)
        {
            if((i%2) == 0)
            {
                vtrCount[i] = vtrCount[i/2];
            }
            else
            {
                vtrCount[i] = vtrCount[i/2] + 1;
            }
        }
        return vtrCount;
    }
};