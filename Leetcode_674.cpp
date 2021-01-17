/*
* 674. 最长连续递增序列
*
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，
那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

提示：
    0 <= nums.length <= 104
    -109 <= nums[i] <= 109
* 
*
* 
* 解题思路： 
*   无
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int res = 1, curRes=1;
        for(int i=1;i < nums.size();++i)
        {
            if(nums[i-1] < nums[i])
                ++curRes;
            else
            {
                if(res < curRes)
                    res = curRes;
                curRes = 1;
            }
        }
        if(res < curRes)
            res = curRes;
        return res;
    }
};
