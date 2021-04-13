/*
* 219. 存在重复元素 II
*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

示例 1:
输入: nums = [1,2,3,1], k = 3
输出: true

示例 2:
输入: nums = [1,0,1,1], k = 1
输出: true

示例 3:
输入: nums = [1,2,3,1,2,3], k = 2
输出: false

* 
* 解题思路： 
*   1. 暴力循环，内循环边界值为k
*   2. 使用 map 记住元素的位置
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;
        for(int i=0;i < nums.size();++i){
            auto iter = myMap.find(nums[i]);
            if(iter == myMap.end()){
                myMap.emplace(nums[i], i);
            }else{
                if(i - iter->second <= k)
                    return true;
                else
                    iter->second = i;
            }
        }
        return false;
    }
};