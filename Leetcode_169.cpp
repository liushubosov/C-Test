/*
* 169. 多数元素
*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1：
输入：[3,2,3]
输出：3

示例 2：
输入：[2,2,1,1,1,2,2]
输出：2

* 
* 解题思路： 
*   
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int count = 0;
        for(int i=0;i < nums.size();++i)
        {
            if(count == 0)
                res = nums[i];
            if(res == nums[i])
                ++count;
            else
                --count;
        }
        return res;
    }
};