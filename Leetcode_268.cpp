/*
* 268. 丢失的数字
*
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

提示：
n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
nums 中的所有数字都 独一无二

*  
* 解题思路：
*   使用异或
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i < nums.size();++i){
            res^=(nums[i]^i);
        }
        res ^= nums.size();
        return res;
    }
};