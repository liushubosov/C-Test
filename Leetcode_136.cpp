/*
* 136. 只出现一次的数字
*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

* 
* 解题思路： 
*   
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto &n : nums){
            res ^= n;
        }
        return res;
    }
};