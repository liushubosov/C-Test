/*
* 198. 打家劫舍
*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

提示：
	0 <= nums.length <= 100
    0 <= nums[i] <= 400
* 
* 解题思路： 
*   
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int prepre = 0;
        int pre = 0;
        int cur = 0;
        for(int i=0;i < nums.size();++i)
        {
            if(i == 0)
                cur = nums[i];
            else if(i == 1)
                cur = max(nums[i],pre);
            else
                cur = max(prepre+nums[i],pre);
            prepre = pre;
            pre = cur;
        }
        return cur;
    }
};