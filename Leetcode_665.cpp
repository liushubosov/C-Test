/*
* 665. 非递减数列
*
给你一个长度为 n 的整数数组，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。

说明：
    1 <= n <= 10 ^ 4
    - 10 ^ 5 <= nums[i] <= 10 ^ 5
* 
*
* 
* 解题思路： 
*   太简单了，略
*/

class Solution {
public:
//[3,4,2,3]
//[4,2,3]
    bool checkPossibility(vector<int>& nums) {
        bool bFlag = false;

        for(int i=0;i < nums.size()-1;++i)
        {
            if(nums[i] > nums[i+1])
            {
                if(bFlag)
                    return false;
                else
                {
                    bFlag = true;
                    if(i-1>=0 && nums[i-1] > nums[i+1])
                        nums[i+1] = nums[i];
                }
            }
        }
        return true;
    }
};