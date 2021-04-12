/*
* 217. 存在重复元素
*
给定一个整数数组，判断是否存在重复元素。

如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

示例 1:
输入: [1,2,3,1]
输出: true

示例 2:
输入: [1,2,3,4]
输出: false

示例 3:
输入: [1,1,1,3,3,4,3,2,4,2]
输出: true

* 
* 解题思路： 
*   1. 使用 set ，边插入边检查
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i < nums.size();++i){
            auto it=s.find(nums[i]);
            if(it != s.end())
                return true;
            else
                s.emplace(nums[i]);
        }
        return false;
    }
};