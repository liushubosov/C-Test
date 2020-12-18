/*
* 693. 交替位二进制数
*

给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。

* 
示例 1：

输入：n = 5
输出：true
解释：5 的二进制表示是：101

*提示：
    1 <= n <= 231 - 1
* 
* 解题思路： 
*   无
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = -2;
        while(n){
            int mod = n&1;
            if(pre != -2 && mod == pre)
                return false;
            pre = mod;
            n = n >> 1;
        }
        return true;
    }
};